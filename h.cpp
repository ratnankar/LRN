#include<iostream>
using namespace std;

class H{

    public:
    
        static int b; 
    
};

int H::b;

int main(){

    H obj;

    cout<<obj.b;

}