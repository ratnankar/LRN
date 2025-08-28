#include<iostream>
using namespace std;

int main(){

    int a[6] = {1,2,3,4,5,0};

    for(int i = 0; i<5; i++){

        bool flag = false;
            
        for(int j = 5; j>0; j--){

            if(a[5-j]>a[5-(j-1)]){

                int k = a[5-j];

                a[5-j] = a[5-(j-1)];

                a[5-(j-1)] = k;

                flag = true;
            }
        }

        if(flag==false&&i==0){

            cout<<"Already Sorted"<<endl;
            break;
        }
        if(flag==false){

            break;
        }
    }

    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5];
}