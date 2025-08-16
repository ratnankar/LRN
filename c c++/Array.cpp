#include<iostream>
using namespace std;

class Array{

    private:

        int capacity;
        int lastIn;
        int *ptr;

    public:

        Array();
        Array(Array&);
        Array& operator=(Array&);
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
        void doubleArray();
        ~Array();
};

Array::Array(){

    ptr = NULL;
}

Array::Array(Array &arr){

    capacity = arr.capacity;
    lastIn = arr.lastIn;
    ptr = new int[capacity];
    for(int i = 0; i<=lastIn; i++){

        ptr[i] = arr.ptr[i];
    }
}

Array& Array::operator=(Array &arr){

    capacity = arr.capacity;
    lastIn = arr.lastIn;
    if(ptr != NULL){
        delete [] ptr;
    }
    ptr = new int[capacity];
    for(int i = 0; i<=lastIn; i++){

        ptr[i] = arr.ptr[i];
    }
    return(*this);
}

void Array::createArray(int cap){

    capacity = cap;
    lastIn = -1;

    if(ptr != NULL){

        delete[] ptr;
    }

    ptr = new int[capacity];
}

void Array::insert(int Index, int dt){

    try{

        if(Index<0 || Index>lastIn+1){

            throw 1;
        }

        if(isFull()){

            throw 2;
        }

        for(int i = lastIn; i>=Index; i--){

            ptr[i+1] = ptr[i];
        }
        ptr[Index] = dt;
        lastIn++;
    }

    catch(int e){

        if(e==1){

            cout<<"Invalid Index";
        }

        if(e==2){

            cout<<"Overflow";
        }
    }
}

void Array::append(int data){

    if(!isFull()){

        lastIn++;
        ptr[lastIn] = data;
    }

    else{

        cout<<"Overflow : Append not performed"<<endl;
    }
}

int Array::getItem(int In){

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

    return lastIn == -1;
}

bool Array::isFull(){

    return lastIn == capacity-1;
}

void Array::del(int Ind){

    try{

        if(Ind<0||Ind>lastIn){

            throw 1;
        }
        for(int i = Ind; i<lastIn; i++){

        ptr[i] = ptr[i+1];
        }
        lastIn--;
    }


    catch(int e){

        if(e==1){

            cout<<"Invalid Index";
        }
    }

}

void Array::edit(int Indx, int el){

    try{

        if(Indx<0||Indx>lastIn){

            throw 1;
        }
        ptr[Indx] = el;
    }

    catch(int e){

        if(e==1){

            cout<<"Invalid Index";
        }
    }
}

int Array::count(){

    return lastIn+1;
}

int Array::getCapacity(){

    return capacity;
}

void Array::doubleArray(){

    int* temp = new int[capacity*2];

    for(int i = 0; i<capacity; i++){

        temp[i] = ptr[i];
    }

    delete[] ptr;

    ptr = temp;

    capacity = capacity*2;
}

Array::~Array(){

    delete[] ptr;
}

int main(){

    Array arr1;

    arr1.createArray(5);
    arr1.insert(0,33);
    arr1.append(34);
    arr1.append(333);
    arr1.del(1);

    Array arr2;
    arr2 = arr1;

    cout<<arr2.getItem(1);

}