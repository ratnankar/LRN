#include<iostream>
using namespace std;

class Array{

    private:

        int capacity;
        int lastIn;
        int *ptr;

    public:
    
        void createArray(int);
        void insert(int, int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
        void edit(int, int);
        int count();
        int getCapacity();
};

Array::Array(){

    ptr = NULL;
}

void Array::createArray(int cap){

    capacity = cap;
    lastIn = -1;

    if(ptr != NULL){

        delete ptr;
    }

    ptr = new int[capacity];
}

int main(){

    Array arr;

    arr.createArray(4);
}