#include<iostream>
using namespace std;

int main(){

    int* p = new int;

    int* q = (int*)malloc(5);

    *p = 34;

    *q = 32;

    cout<<*p<<" "<<*q;

    free(p);

    free(q);

}