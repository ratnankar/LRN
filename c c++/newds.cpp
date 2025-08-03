#include<iostream>
using namespace std;

class Array{

    private:

        int capacity;
        int cur;
        int *p;

    public:
    
    void newarray(){

        p = new int;
    
    }

    void insarray(){

        printf("Enter the element : ");
        scanf("%d",&(p[0]));

    }

    void disarray(){

        cout<<p[0];

    }

};

int main(){

    Array obj1;

    obj1.newarray();
    obj1.insarray();
    obj1.disarray();

}