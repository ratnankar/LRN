#include<iostream>
using namespace std;

struct node{

    node* next;
    int item;
};

class CLL{

    node* last;

    public:
        
        CLL();
        CLL(CLL&);
        CLL& operator=(CLL&);
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*, int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void edit(node*, int);
        node* search(int);
        int count();
        ~CLL();
};

CLL::CLL(){

    last = NULL;
}

CLL::CLL(CLL& l){

    node* t = l.last->next;

    while(t != l.last->next){

        insertAtLast(t->item);
        t = t->next;
    }
}

CLL& CLL::operator=(CLL& l){

    while(last==NULL){

        deleteFirst();
    }

    node* t = l.last->next;

    while(t != l.last->next){

        insertAtLast(t->item);
        t = t->next;
    }

    return *this;
}

void CLL::insertAtFirst(int data){

    node* n = new node;
    n->item= data;

    if(last==NULL){

        last = n;
        n->next = n;
    }
    else{

        n->next = last->next;
        last->next = n;
    }
}

void CLL::insertAtLast(int data){

    node* n = new node;
    n->item = data;

    if(last==NULL){

        last = n;
        n->next = n;
    }
    else{

        n->next = last->next;
        last->next = n;
        last = n;
    } 
}

void CLL::insertAfter(node* t, int data){

    node* n = new node;

    n->item = data;
    n->next = t->next;
    t->next = n;
}

void CLL::deleteFirst(){

    node* t = last->next;

    last = last->next->next;

    delete t;
}

void CLL::deleteLast(){

    node* t = last;

    while(t->next != last){

        t = t->next;
    }

    t->next = last->next;

    delete last;

    last = t;
}

void CLL::deleteNode(node* t){

    node* n = last;

    while(n->next != t){

        n = n->next;
    }
    
    n->next = t->next;

    delete t;
}

void CLL::edit(node* t, int data){

    t->item = data;
}

node* CLL::search(int data){

    node* t = last;

    while(t->item != data){

        t = t->next;
    }

    return t;
}

int CLL::count(){
    
    if(last==NULL){

        return 0;
    }

    int i = 1;
    node* t = last->next;

    while(t->next != last->next){

        t = t->next;
        i++;
    }
        
    return i;

}

CLL::~CLL(){

    while(last){

        deleteFirst();
    }
}

int main(){

    CLL obj1;

    obj1.insertAtFirst(34);
    obj1.insertAtLast(56);
    obj1.insertAtFirst(23);
    obj1.insertAtLast(12);

    int a = obj1.count();

    cout<<a;
}

