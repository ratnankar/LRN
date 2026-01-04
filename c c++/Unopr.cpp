#include<iostream>
using namespace std;

class Complex{

    public:

    int a;
    int b;

        Complex operator++(){

            Complex temp;

            temp.a = ++a;
            temp.b = ++b;

            return temp;
        }

};

int main(){

    Complex c1,c2;

    c1.a = 2;
    c1.b = 4;

    c2 = ++c1;

    cout<<"a = "<<c2.a<<" ,b = "<<c2.b;

}
