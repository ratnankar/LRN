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
        int search(int);
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

        while(t->next != NULL){

            t = t->next;
        }

        t->next = n;
    }
        
}

int SLL::search(int In){

    try{

        node* t = start;
        int i;

        for(i = 0; t->next !=NULL; i++){

            t = t->next;
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

int main(){

    SLL obj1;

    obj1.insertAtStart(73);
    obj1.insertAtLast(34);
    obj1.insertAtLast(37);

    int k;

    cout<<"Enter the index to search : ";
    cin>>k;

    int a = obj1.search(k);

    cout<<a;
}