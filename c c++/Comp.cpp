#include<iostream>
using namespace std;

class comp{

    int a,b;

    public :

        void setnum(int, int);

        void disnum();

        comp add(comp);

};

    void comp::setnum(int x, int y){

        a = x;
        b = y;

    }

    void comp::disnum(){

        cout<<"a = "<<a<<", b = "<<b;

    }

    comp comp::add(comp c){

        comp temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return temp;
    }


int main(){

    comp obj,obj1,obj3;

    obj.setnum(2,3);
    obj1.setnum(4,5);
    obj3 = obj.add(obj1);

    obj3.disnum();

}