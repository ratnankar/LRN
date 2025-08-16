#include<iostream>
using namespace std;

class A{

    int a;
    int b;

    public:

        void setdata(int x, int y){a = x; b = y;}
        // A operator+(int q){

        //     A temp;
        //     temp.a = a+q;
        //     temp.b = b;

        //     return temp;
        // }
        friend A operator+(int,A);
};

A operator+(int k, A i){

    A temp;

    temp.a = i.a + k;
    temp.b = i.b;

    return temp;

}

int main(){

    A obj1,obj2;

    obj1.setdata(4,6);
    obj2.setdata(6,1);

    A obj3;
    obj3 = 3+obj3;

}