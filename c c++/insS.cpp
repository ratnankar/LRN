#include<iostream>
using namespace std;

int main(){

    int a[10] = {40,21,38,68,70,25,90,18,7,54};

    for(int s = 0; s<10; s++){

        int temp = a[s+1];

        for(int i = s; i>=0; i--){

            int j = s;
            if(a[i]>a[s+1]){

                a[s+1] = a[i];
                j--;
            }
        }
    }

    for(int i = 0; i<10; i++){

        cout<<a[i]<<" ";
    }
}