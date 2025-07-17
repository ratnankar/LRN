#include<iostream>
using namespace std;
int num(int);

int main(){

    int m;
    num(5);
    num(6);
    m = num(3);

    cout<<m;
    
}

int num(int j){

    static int n;

    if(n==0){
    
        n = j;
    
    }

    else{

        n= n*j;

    }

    return n;

}