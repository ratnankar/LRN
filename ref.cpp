#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

    int a = 2;
    int* b = &a;
    int* c = &*b;
    int &d = a;
    int* e = &d;
    // int* d = 3;

    cout<<b<<"\n"<<c<<"\n"<<&d<<"\n"<<e;

    printf("\n%d\n%d",b,c);

    printf("\n%d",*&*b);

}