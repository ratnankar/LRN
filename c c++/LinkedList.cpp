#include<iostream>
using namespace std;

struct node{

    int item;
    node* next;
};

class SLL{

    public:
        node* start;
        node* curptr;

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
    if(start==NULL){

        curptr = n;
    }
    start = n;
}

void SLL::insertAtLast(int data){

    node* n = new node;
    curptr = n;
    n->item = data;
    n->next = NULL;
}

int main(){

    SLL obj1;

    obj1.insertAtStart(90);
    obj1.insertAtStart(78);
    obj1.insertAtLast(45);
    obj1.insertAtLast(23);
    obj1.insertAtStart(26);

    cout<<obj1.curptr->item;
}