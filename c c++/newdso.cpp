#include<iostream>
using namespace std;

class Array{

    private:
        int capacity;
        int lastIn;
        int* ptr;

    public:
    
        Array();
        Array(Array&);
        Array& operator=(Array&);
        void createArray(int);
        void append(int);
        void insert(int, int);
        void delEl(int);
        void edit(int, int);
        int getEl(int);
        bool isEmpty();
        bool isFull();
        int count();
        int getCap();
        void dblArray();
        ~Array();
};

Array::Array(){

    ptr = nullptr;
}

Array::Array(Array& arr){

    capacity = arr.capacity;
    lastIn = arr.lastIn;
    ptr = new int[capacity];

    for(int i = 0; i<=lastIn; i++){

        ptr[i] = arr.ptr[i];
    }
}

Array& Array::operator=(Array& arr){

    capacity = arr.capacity;
    lastIn = arr.lastIn;
    if(ptr != nullptr){

        delete[] ptr;
    }
    ptr = new int[capacity];

    for(int i = 0; i<=lastIn; i++){

        ptr[i] = arr.ptr[i];
    }

    return *this;
}

void Array::createArray(int cap){

    capacity = cap;
    lastIn = -1;
    ptr = new int[capacity];
}

void Array::append(int data){

    if(isFull()){

        cout<<"Array Overflow"<<endl;
    }
    else{

        ptr[++lastIn] = data;
    }
}

void Array::insert(int In, int data){

    try{

        if(In<0||In>lastIn+1){

            throw 1;
        }

        if(isFull()){

            throw 2;
        }

        int i;

        for(i = lastIn; i>=In; i--){

            ptr[i+1] = ptr[i];
        }

        ptr[In] = data;
        lastIn++;
    }

    catch(int e){

        if(e==1){

            cout<<"Invalid Index"<<endl;
        }

        if(e==2){

            cout<<"Array Overflow"<<endl;
        }
    }
}

void Array::delEl(int In){

    if(In<0||In>lastIn){

        cout<<"Invalid Index"<<endl;
    }

    else{

        for(int i = In; i<lastIn; i++){

            ptr[i] = ptr[i+1];
        }

        lastIn--;
    }
}

void Array::edit(int In, int data){

    if(In<0||In>lastIn){

        cout<<"Invalid Index"<<endl;
    }

    else{

        ptr[In] = data;
    }
}

int Array::getEl(int In){

    try{

        if(In<0||In>lastIn){

            throw 1;
        }

        return ptr[In];
    }

    catch(int e){

        if(e==1){

            cout<<"Invalid Index";
        }
    }

    return -1;
}

bool Array::isEmpty(){

    if(lastIn==-1){

        return 1;
    }

    else{

        return 0;
    }
}

bool Array::isFull(){

    if(lastIn==capacity-1){

        return 1;
    }

    else{

        return 0;
    }
}

int Array::count(){

    return lastIn+1;
}

int Array::getCap(){

    return capacity;
}

void Array::dblArray(){

    capacity = capacity*2;
    int* temp = new int[capacity];

    for(int i = 0; i<=lastIn; i++){

        temp[i] = ptr[i];
    }

    delete[] ptr;

    ptr = temp;
}

Array::~Array(){

    delete[] ptr;
}

int main(){

    Array arr1;

    arr1.createArray(5);
    arr1.append(23);
    arr1.append(34);
    arr1.append(85);

    Array arr2,arr3;

    arr3 = arr2 = arr1;

    cout<<arr3.getEl(1);
}