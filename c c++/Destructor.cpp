#include<iostream>
using namespace std;

class A{

    int *p;

    public:

    A(){

        p = new int;

    }

    void setvalue(int a){

        *p = a;

    }

    int getvalue(){

        return *p;

    }

    ~A(){

        delete(p);

    }

};

int main(){

    A obj;

    obj.setvalue(34);
    int a = obj.getvalue();

    cout<<a;

    return 0;

}