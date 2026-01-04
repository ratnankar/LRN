#include<iostream>
using namespace std;

struct node{

    node* prev;
    int item;
    node* next;
};

class DLL{

    node* start;

    public:

        DLL();
        DLL(DLL&);
        DLL& operator=(DLL&);
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void edit(node*,int);
        node* search(int);
        int count();
        ~DLL();
};

DLL::DLL(){

    start = NULL;
}

DLL::DLL(DLL& l){

    node* t = l.start;

    while(t){

        insertAtLast(t->item);
        t->next;
    }
}

DLL& DLL::operator=(DLL& l){

    while(start){

        deleteFirst();
    }

    node* t = l.start;

    while(t){

        insertAtLast(t->item);
        t->next;
    }

    return *this;
}

void DLL::insertAtStart(int data){

    node* n = new node;
    n->item = data;
    n->prev = NULL;
    
    if(start==NULL){

        n->next == NULL;
        start = n;
    }
    else{

        n->next = start;
        start->prev = n;
        start = n;
    }
}

void DLL::insertAtLast(int data){

    node* n = new node;
    n->item = data;
    n->next = NULL;

    if(start==NULL){

        n->prev = NULL;
        start = n;
    }
    else{

        node* t = start;

        while(t->next != NULL){

            t = t->next;
        }

        n->prev = t;
        t->next = n;
    }
}

void DLL::insertAfter(node* t, int data){

    try{

        if(start==NULL){

            throw 1;
        }

        node* n = new node;
        n->item = data;
        n->next = t->next;
        n->prev = t;
        t->next = n;
    }
    catch(int e){

        if(e==1){

            cout<<"The List is empty";
        }
    }
}

void DLL::deleteFirst(){

    node* t = start;
    start->next->prev = NULL;
    start = start->next;

    delete t;

}

void DLL::deleteLast(){

    node* t;

    t = start;

    while(t){

        t = t->next;
    }

    t->prev = NULL;

    delete t;
}

void DLL::deleteNode(node* t){

    t->next->prev = t->prev;
    t->prev->next = t->next;

    delete t;
}

void DLL::edit(node* t, int data){

    t->item = data;
}

node* DLL::search(int data){

    node* t = start;

    while(t->item!=data){

        t = t->next;

        if(t==start){

            return NULL;
        }
    }

    return t;
}

int DLL::count(){

    node* t = start;

    if(start==NULL){

        return 0;
    }

    int i = 1;

    while(t->next != NULL){

        t = t->next;
        i++;
    }

    return i;
}

DLL::~DLL(){

    while(start){

        deleteFirst();
    }
}

int main(){

    DLL obj1;

    obj1.insertAtStart(48);
    obj1.insertAtLast(72);

    int a = obj1.count();

    cout<<a;
}