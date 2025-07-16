#include<iostream>
using namespace std;

class comp{

    int a,b;

    public :

        void setnum(int x, int y){

            a = x;
            b = y;
            
        }

        void disnum(){

            cout<<"a = "<<a<<", b = "<<b;

        }

};


int main(){

    comp obj;

    obj.setnum(2,3);
    obj.disnum();

}