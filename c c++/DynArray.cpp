#include<iostream>
using namespace std;

class dynArray{

    private:
        int capacity;
        int lastIn;
        int* ptr;

    public:

        dynArray();
        dynArray(dynArray&);
        dynArray& operator=(dynArray&);
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
        void halfArray();
        ~dynArray();
};

dynArray::dynArray(){

    ptr = nullptr;
}

dynArray::dynArray(dynArray& arr){

    capacity = arr.capacity;
    lastIn = arr.lastIn;
    ptr = new int[capacity];

    for(int i = 0; i<=lastIn; i++){

        ptr[i] = arr.ptr[i];
    }
}

dynArray& dynArray::operator=(dynArray& arr){

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

void dynArray::createArray(int cap){

    capacity = cap;
    lastIn = -1;
    ptr = new int[capacity];
}

void dynArray::append(int data){

    if(isFull()){

        dblArray();
    }

        ptr[++lastIn] = data;
}

void dynArray::insert(int In, int data){

    try{

        if(In<0||In>lastIn+1){

            throw 1;
        }

        if(isFull()){

            dblArray();
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
    }
}

void dynArray::delEl(int In){

    if(In<0||In>lastIn){

        cout<<"Invalid Index"<<endl;
    }

    else{

        for(int i = In; i<lastIn; i++){

            ptr[i] = ptr[i+1];
        }

        lastIn--;
    }

    if(lastIn+1==capacity/2){

        halfArray();
    }
}

void dynArray::edit(int In, int data){

    if(In<0||In>lastIn){

        cout<<"Invalid Index"<<endl;
    }

    else{

        ptr[In] = data;
    }
}

int dynArray::getEl(int In){

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

bool dynArray::isEmpty(){

    if(lastIn==-1){

        return 1;
    }

    else{

        return 0;
    }
}

bool dynArray::isFull(){

    if(lastIn==capacity-1){

        return 1;
    }

    else{

        return 0;
    }
}

int dynArray::count(){

    return lastIn+1;
}

int dynArray::getCap(){

    return capacity;
}

void dynArray::dblArray(){

    capacity = capacity*2;
    int* temp = new int[capacity];

    for(int i = 0; i<=lastIn; i++){

        temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
}

void dynArray::halfArray(){

    capacity /=2;
    int* temp = new int[capacity];

    for(int i = 0; i<capacity; i++){

        temp[i] = ptr[i];
    }

    delete[] ptr;
    ptr = temp;
}

dynArray::~dynArray(){

    delete[] ptr;
}

int main(){

    dynArray arr1;

    arr1.createArray(5);
    arr1.append(23);
    arr1.append(34);
    arr1.append(85);

    dynArray arr2,arr3;

    arr3 = arr2 = arr1;

    cout<<arr3.getEl(1);
}