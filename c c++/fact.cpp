#include<iostream>
using namespace std;

int factorial(int f){

    if(f<0){

        cout<<"Enter a valid number"<<endl;
        return -1;
    }
    else if((f==0) || (f==1)){

        return 1;
    }
    else{

        return f*factorial(f-1);
    }
}

int main(){

    int n;

    cout<<"Enter the number: ";
    cin>>n;

    int a = factorial(n);

    cout<<"Factorial of "<<n<<" is "<<a;
}