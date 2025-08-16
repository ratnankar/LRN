#include<iostream>
using namespace std;

int add(int,int,int=0);
int sub(int,int,int=0);

int main(){

    int o,a,b,t,c,s;

    cout<<"Select the fllowing operation :";
    cout<<"\n"<<"1. Add\n2. Subtract\n";

    cout<<"Enter : ";
    cin>>o;

    if(o==1||o==2){
        cout<<"\nEnter First number : ";

        cin>>a;

        cout<<"Enter Second number : ";

        cin>>b;

        cout<<"Want to enter third number : \n1. Yes\n2. No\n-->";

        cin>>t;

        if(t==1){

        cout<<"Enter Third number : ";

        cin>>c;

        }

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

    else{

    cout<<"\nInvalid Input";

    }

}

int add(int x,int y,int z){

    return x+y+z;

}

int sub(int x,int y,int z){

    return x-y-z;

}