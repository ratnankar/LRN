#include<iostream>
using namespace std;

class A{

    public:

        A(){

            cout<<"A Called\n";
        }

        void bnk(){};

};

int main(){

    A obj;
    obj.bnk();
    A obj2;

}