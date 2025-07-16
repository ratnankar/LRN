#include<iostream>
using namespace std;

class N{
    
    public:

        void g();

};

void N::g(){

    cout<<"g called";
}


int main(){

    N obj;

    obj.g();
    
}