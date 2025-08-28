#include<iostream>
using namespace std;

int main(){

    int a[6] = {6,5,4,3,2,1};

    for(int i = 0; i<5; i++){

        for(int j = 5; j>0; j--){

            if(a[5-j]>a[5-(j-1)]){

                int k = a[5-j];

                a[5-j] = a[5-(j-1)];

                a[5-(j-1)] = k;
            }
        }
    }

    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<" "<<a[6];
}