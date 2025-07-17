#include<iostream>
using namespace std;

class A{

    public:

        A(int a){

            cout<<a<<"\n";
        }

        void bnk(){};

};

int main(){

    A obj(5);
    obj.bnk();
    A obj2(10);

}