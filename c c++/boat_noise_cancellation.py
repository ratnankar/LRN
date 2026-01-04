import numpy as np
import sounddevice as sd
import threading
import queue
import time
from scipy import signal
import argparse
import sys

class BoatEarphoneNoiseCanceller:
    def __init__(self, sample_rate=44100, block_size=1024):
        self.sample_rate = sample_rate
        self.block_size = block_size
        self.audio_queue = queue.Queue()
        self.is_processing = False
        self.noise_threshold = 0.03
        self.volume_boost = 1.2
        
        # Initialize device attributes
        self.input_device = None
        self.output_device = None
        
        # Boat earphone specific settings
        self.frequency_response = {
            'low_cut': 80,     'voice_low': 150, 
            'voice_high': 4000, 'high_cut': 8000
        }
        
        print("Boat Earphone Noise Cancellation Initialized")
        print(f"Sample rate: {sample_rate} Hz, Block size: {block_size} samples")
        
    def list_devices(self):
        """List available audio devices"""
        print("\nAvailable audio devices:")
        devices = sd.query_devices()
        for i, device in enumerate(devices):
            print(f"{i}: {device['name']} (Input: {device['max_input_channels']}, Output: {device['max_output_channels']})")
    
    def set_devices(self, input_device_id=None, output_device_id=None):
        """Set specific input and output devices"""
        try:
            if input_device_id is not None:
                sd.check_input_settings(device=input_device_id, channels=1, samplerate=self.sample_rate)
                self.input_device = input_device_id
                print(f"Set input device to: {sd.query_devices(input_device_id)['name']}")
            
            if output_device_id is not None:
                sd.check_output_settings(device=output_device_id, channels=1, samplerate=self.sample_rate)
                self.output_device = output_device_id
                print(f"Set output device to: {sd.query_devices(output_device_id)['name']}")
            
            return True
        except Exception as e:
            print(f"Error setting device: {e}")
            return False
    
    def capture_audio(self):
        """Capture audio from microphone"""
        def audio_callback(indata, frames, time, status):
            if status:
                print(f"Audio status: {status}")
            self.audio_queue.put(indata.copy())
        
        try:
            # Use specified device or default input device
            device = self.input_device if self.input_device is not None else sd.default.device[0]
            
            with sd.InputStream(callback=audio_callback, channels=1, 
                               samplerate=self.sample_rate, blocksize=self.block_size,
                               device=device):
                while self.is_processing:
                    time.sleep(0.1)
        except Exception as e:
            print(f"Error capturing audio: {e}")
    
    def apply_boat_specific_eq(self, audio_data):
        """Apply EQ settings optimized for Boat earphones"""
        # 1. Reduce low-frequency rumble
        sos_low = signal.butter(4, self.frequency_response['low_cut']/(self.sample_rate/2), 
                               btype='highpass', output='sos')
        filtered_audio = signal.sosfilt(sos_low, audio_data)
        
        # 2. Boost voice frequencies
        sos_voice = signal.butter(4, [
            self.frequency_response['voice_low']/(self.sample_rate/2),
            self.frequency_response['voice_high']/(self.sample_rate/2)
        ], btype='bandpass', output='sos')
        voice_boost = signal.sosfilt(sos_voice, filtered_audio) * 1.5
        
        # 3. Reduce high-frequency hiss
        sos_high = signal.butter(4, self.frequency_response['high_cut']/(self.sample_rate/2), 
                                btype='lowpass', output='sos')
        filtered_audio = signal.sosfilt(sos_high, filtered_audio + voice_boost)
        
        return filtered_audio
    
    def adaptive_noise_reduction(self, audio_data):
        """Apply adaptive noise reduction based on audio content"""
        # Calculate RMS to detect if this is noise or voice
        rms = np.sqrt(np.mean(audio_data**2))
        
        if rms < self.noise_threshold:
            # Likely noise, apply stronger filtering
            sos_strong = signal.butter(6, [
                self.frequency_response['voice_low']/(self.sample_rate/2),
                self.frequency_response['voice_high']/(self.sample_rate/2)
            ], btype='bandpass', output='sos')
            return signal.sosfilt(sos_strong, audio_data) * self.volume_boost
        else:
            # Likely voice, apply gentler filtering
            return self.apply_boat_specific_eq(audio_data)
    
    def process_audio(self):
        """Process audio with noise cancellation"""
        try:
            # Use specified device or default output device
            device = self.output_device if self.output_device is not None else sd.default.device[1]
            
            while self.is_processing:
                try:
                    # Get audio block from queue
                    audio_data = self.audio_queue.get(timeout=0.1)
                    
                    # Apply noise cancellation
                    cleaned_audio = self.adaptive_noise_reduction(audio_data.flatten())
                    
                    # Prevent clipping
                    cleaned_audio = np.clip(cleaned_audio, -1.0, 1.0)
                    
                    # Play the cleaned audio
                    sd.play(cleaned_audio, self.sample_rate, device=device)
                    
                except queue.Empty:
                    continue
                    
        except Exception as e:
            print(f"Error processing audio: {e}")
    
    def calibrate(self, calibration_time=3):
        """Calibrate to ambient noise"""
        print("Please be silent during calibration...")
        time.sleep(1)
        
        calibration_data = []
        def calibration_callback(indata, frames, time, status):
            calibration_data.append(indata.copy())
        
        # Use specified device or default input device
        device = self.input_device if self.input_device is not None else sd.default.device[0]
        
        with sd.InputStream(channels=1, samplerate=self.sample_rate, 
                           blocksize=self.block_size, device=device,
                           callback=calibration_callback):
            time.sleep(calibration_time)
        
        if calibration_data:
            all_data = np.concatenate(calibration_data)
            noise_level = np.sqrt(np.mean(all_data**2))
            self.noise_threshold = max(0.01, noise_level * 1.5)
            print(f"Calibration complete. Noise threshold set to: {self.noise_threshold:.4f}")
    
    def start(self, input_device_id=None, output_device_id=None):
        """Start noise cancellation"""
        if not self.set_devices(input_device_id, output_device_id):
            print("Failed to set devices. Using default devices.")
        
        print("Starting Boat earphone noise cancellation...")
        self.calibrate()
        
        self.is_processing = True
        
        # Start audio capture thread
        capture_thread = threading.Thread(target=self.capture_audio)
        capture_thread.daemon = True
        capture_thread.start()
        
        # Start processing thread
        process_thread = threading.Thread(target=self.process_audio)
        process_thread.daemon = True
        process_thread.start()
        
        print("Noise cancellation is active. Press Enter to stop...")
        try:
            input()  # Wait for user to press Enter
        except:
            pass
        finally:
            self.stop()
    
    def stop(self):
        """Stop noise cancellation"""
        print("Stopping noise cancellation...")
        self.is_processing = False
        time.sleep(0.5)

def main():
    parser = argparse.ArgumentParser(description='Boat Earphone Noise Cancellation Software')
    parser.add_argument('-l', '--list-devices', action='store_true', help='List audio devices')
    parser.add_argument('-i', '--input-device', type=int, help='Specify input device ID')
    parser.add_argument('-o', '--output-device', type=int, help='Specify output device ID')
    parser.add_argument('-s', '--sample-rate', type=int, default=44100, help='Sample rate (default: 44100)')
    parser.add_argument('-b', '--block-size', type=int, default=1024, help='Block size (default: 1024)')
    
    args = parser.parse_args()
    
    nc = BoatEarphoneNoiseCanceller(sample_rate=args.sample_rate, block_size=args.block_size)
    
    if args.list_devices:
        nc.list_devices()
        return
    
    try:
        nc.start(input_device_id=args.input_device, output_device_id=args.output_device)
    except KeyboardInterrupt:
        print("\nStopping...")
        nc.stop()
    except Exception as e:
        print(f"Error: {e}")
        nc.stop()

if __name__ == "__main__":
    main()