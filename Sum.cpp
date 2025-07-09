#include<iostream>
using namespace std;

int add(int,int);
int add(int,int,int);
int sub(int,int);
int sub(int,int,int);

int main(){

    int o,a,b,c,s;

    cout<<"Select the fllowing operation :";
    cout<<"\n"<<"1. Add\n2. Subtract\n";

    cout<<"Enter : ";
    cin>>o;

    if(o==1||o==2){
        cout<<"\nEnter First number : ";

        cin>>a;

        cout<<"Enter Second number : ";

        cin>>b;

        cout<<"Enter Third number : ";

    cin>>c;

    if(o==1) {

    s = add(a,b,c);

    cout<<"\nSum of the numbers is "<<s;
    
    }

    if(o==2) {

    s = sub(a,b,c);

    cout<<"\nSubtraction of the numbers is "<<s;
    
    }

    cout<<" ";
    }

    cout<<"Enter invalid Input";

}

int add(int x,int y){

    return x+y;

}

int add(int x,int y,int z){

    return x+y+z;

}

int sub(int x,int y){

    return x-y;

}

int sub(int x,int y,int z){

    return x-y-z;

}