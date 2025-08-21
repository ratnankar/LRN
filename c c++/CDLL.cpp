#include<iostream>
using namespace std;

struct node{

    node* prev;
    int item;
    node* next;
};

class CDLL{

    node* last;

    public:

        CDLL();
        CDLL(CDLL&);
        CDLL& operator=(CDLL&);
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*, int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void edit(node*, int);
        node* search(int);
        int count();
        ~CDLL();
};

CDLL::CDLL(){

    last = NULL;
}

CDLL::CDLL(CDLL& l){

    last = NULL;

    node* t = l.last->next;

    while(t->next!=l.last->next){

        insertAtLast(t->item);
        t = t->next;
    }
}

CDLL& CDLL::operator=(CDLL& l){

    while(last!=NULL){

        deleteFirst();
    }

    node* t = l.last->next;

    while(t->next!=l.last->next){

        insertAtLast(t->item);
        t = t->next;
    }

    return *this;
}

void CDLL::insertAtFirst(int data){

    node* n = new node;
    n->item = data;

    if(last==NULL){

        n->prev = n;
        n->next = n;
        last = n;
    }
    else{

        n->prev = last;
        n->next = last->next;
        last->next = n;
        n->next->prev = n;
    }
}

void CDLL::insertAtLast(int data){

    node* n = new node;
    n->item = data;

    if(last==NULL){

        n->prev = n;
        n->next = n;
        last = n;
    }
    else{

        n->prev = last;
        n->next = last->next;
        last->next->prev = n;
        last->next = n;
        last = n;
    }
}

void CDLL::insertAfter(node* t, int data){

    node* n = new node;
    n->item = data;

    if(t==last){

        n->prev = t;
        n->next = t->next;
        t->next->prev = n;
        t->next = n;
        last =n;
    }
    else{

        n->prev = t;
        n->next = t->next;
        t->next = n;
    }
}

void CDLL::deleteFirst(){

    try{

        if(last==NULL){

            throw 1;
        }

        node* t = last->next;

        t->next->prev = last;
        last->next = t->next;

        delete t;
    }
    catch(int e){

        if(e==1){

            cout<<"List is Empty"<<endl;
        }
    }
}

void CDLL::deleteLast(){

    node* t = last;

    last->next->prev = last->prev;
    last->prev->next = last->next;

    last = last->prev;

    delete t;
}

void CDLL::deleteNode(node* t){

    if(t==last){

        t->prev->next = t->next;
        t->next->prev = t->prev;

        last = last->prev;

        delete t;
    }
    else{

        t->prev->next = t->next;
        t->next->prev = t->prev;

        delete t;
    }
}

void CDLL::edit(node* t, int data){

    t->item = data;
}

node* CDLL::search(int data){

    node* t = last;

    while(t->item != data){

        t = t->next;

        if(t==last){

            return NULL;
        }
    }

    return t;
}

int CDLL::count(){

    if(last==NULL){

        return 0;
    }

    node* t = last->next;
    int i = 1;

    while(t->next!=last->next){

        t = t->next;
        i++;
    }

    return i;
}

CDLL::~CDLL(){

    while(last!=NULL){

        deleteFirst();
    }
}

int main(){

    CDLL obj1;

    obj1.insertAtFirst(34);
    obj1.insertAtLast(23);
    obj1.insertAtFirst(20);

    int a = obj1.count();

    cout<<a;
}