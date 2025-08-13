#include<iostream>
using namespace std;

struct node{

    int item;
    node* next;
};

class SLL{

    node* start;

    public:
        
        SLL();
        SLL(SLL&);
        SLL operator=(SLL&);
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter();
        void deleteFirst();
        void deleteLast();
        void deleteNode();
        void edit();
        int getData(int);
        node* search(int);
        int count();
        // ~SLL();
};

SLL::SLL(){

    start=NULL;
}

void SLL::insertAtStart(int data){

    node* n = new node;
    n->item = data;
    n->next = start;
    start = n;
}

void SLL::insertAtLast(int data){

    node* n = new node;
    node* t;
    n->item = data;
    n->next = NULL;

    t = start;
    
    if(start==NULL){

        start = n;
    }
    else{

        while(t->next){

            t = t->next;
        }

        t->next = n;
    }
        
}

int SLL::getData(int In){

    try{

        node* t = start;
        int i;

        while(t->next){

            t = t->next;
            i++;
        }

        if(In>i||In<0){

            throw 0;
        }

        t = start;

        for(int i = 0; i<In; i++){

            t = t->next;
        }

        return t->item;

    }
    catch(int e){

        cout<<"Invalid Index"<<endl;

        return -1;
    }

}

node* SLL::search(int data){

    node* t = start;

    while(t->item != data){

        t = t->next;
        if(t==NULL){

            return t;
        }
    }

    return t;
}

int main(){

    SLL obj1;

    obj1.insertAtStart(73);
    obj1.insertAtLast(34);
    obj1.insertAtLast(37);

    int k;

    cout<<"Enter the index to search : ";
    cin>>k;

    int a = obj1.getData(k);

    node* b = obj1.search(9);

    cout<<a<<endl<<b;
}