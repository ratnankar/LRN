#include<iostream>
using namespace std;

class H{

    public:

        static int b; 
    
        static void k(){

            cout<<"Static member function can only call static variables";

        }
};

int H::b = 2;

int main(){

    H::k();

    H obj;

    H::b = 5;

    cout<<endl<<obj.b;

}