#include<iostream>
using namespace std;

class num{

    int a;
    int b;

    public:

        void setnum(){

            cout<<"Enter the complex number :-\n"
            <<"Enter the value of real part: ";
            cin>>a;

            cout<<"Enter the imaginary part : ";
            cin>>b;

        }

        void disnum(){

            cout<<"\nThe Complex number is "<<a<<"+"<<b<<"i";

        }

};

int main(){

    num n;

    n.setnum();

    n.disnum();

}