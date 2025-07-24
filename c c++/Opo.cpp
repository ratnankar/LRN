#include<iostream>
using namespace std;

class A{

    public:

        A(int m){

            cout<<m<<"\n";
            
        }

        void operator-(int a){

            cout<<a;

        }


};

int main(){

    int a = 3;
    int b = 4;

    A obj(3);

    obj-3;

}