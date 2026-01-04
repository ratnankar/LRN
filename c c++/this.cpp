#include<iostream>
using namespace std;

class A{

    int a;
    int b;

    public:
        void setdata(int a, int b){

            this->a = a;
            this->b = b;

        }

        void getdata(){

            cout<<"a = "<<a<<", b = "<<b;
            cout<<endl;
        }

};

void f1(A);

int main(){

    int q = 3;
    int r = 4;

    A obj1;
    obj1.setdata(q, r);
    obj1.getdata();

    f1(obj1);

}

void f1(A o){

    o.getdata();

}