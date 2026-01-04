#include<iostream>
using namespace std;

int main(){

    int a[6] = {1,8,3,4,5,7};

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

    for(int i = 0; i<6; i++){

        if(i==6-1){

            cout<<a[i];
        }
        else{

            cout<<a[i]<<" ";
        }
    }
}