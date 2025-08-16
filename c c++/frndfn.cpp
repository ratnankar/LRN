#include<iostream>
using namespace std;

class B{

    public:

        void f1(A);

};

class A{

    int a;
    int b;

    public:

        void setdata(int x, int y){ a = x; b = y;}

        friend void B::f1(A);

};

void B::f1(A i)
{
    int c = i.a + i.b;

    cout<<"Sum of a and b is "<<c;
}

int main(){

    A obj1;
    obj1.setdata(4,5);

    B obj2;
    obj2.f1(obj1);

}