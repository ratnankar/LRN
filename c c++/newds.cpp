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

void Array::append(int data){

    if(!isFull()){

        lastIn++;
        ptr[lastIn] = data;
    }

    else{

        cout<<"Data Overflow"<<endl;
    }
}

int Array::getItem(int In){

    return ptr[In];
}

bool Array::isEmpty(){

    return lastIn == -1;
}

bool Array::isFull(){

    return lastIn == capacity-1;
}

void Array::del(int Ind){

    for(int i = Ind; i<lastIn; i++){

        ptr[i] = ptr[i+1];
    }

    lastIn--;
}

void Array::edit(int Indx, int el){

    ptr[Indx] = el;
}

int Array::count(){

    return lastIn+1;
}

int Array::getCapacity(){

    return capacity;
}

int main(){

    Array arr;

    arr.createArray(4);

    
}