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
        SLL& operator=(SLL&);
        void insertAtStart(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        void edit(node*,int);
        node* search(int);
        int count();
        ~SLL();
};

SLL::SLL(){

    start=NULL;
}

SLL::SLL(SLL& l){

    start = NULL;
    node* n = l.start;

    while(n){

        insertAtLast(n->item);
        n=n->next;
    }
}

SLL& SLL::operator=(SLL& l){

    while(start!=NULL){

        deleteFirst();
    }
    node* n = l.start;

    while(n){

        insertAtLast(n->item);
        n=n->next;
    }

    return *this;
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

void SLL::insertAfter(node* p, int data){

    if(p){

        node* n = new node;
        n->next = p->next;
        p->next = n;
    }
}

node* SLL::search(int data){

    node* t = start;

    while(t){

        if(t->item==data){

            return t;
        }

        t = t->next;
    }

    return t;
}

void SLL::deleteFirst(){

    if(start!=NULL){

        node* n;
        n = start;
        start = start->next;
        delete n; 
    }
}

void SLL::deleteLast(){

    if(start!=NULL){

        node* n = start;
        while(n->next->next){

            n = n->next;
        }
        delete n->next;

        n->next = NULL;
    }
}

void SLL::deleteNode(node* t){

    node* n = start;

    while(n->next!=t){

        n = n->next;
    }

    n->next = t->next;
    
    delete t;
}

int SLL::count(){

    int i = 1;
    node* n = start;

    if(start==NULL){

        return 0;
    }

    while(n->next != NULL){

        n = n->next;
        i++;
    }

    return i;
}

void SLL::edit(node* n, int data){

    n->item = data;
}

SLL::~SLL(){

    while(start!=NULL){

        deleteFirst();
    }
}

int main(){

    SLL obj1;

    obj1.insertAtLast(23);
    obj1.insertAtLast(24);

    SLL obj2 = obj1;

    cout<<obj1.search(23)<<endl;
    cout<<obj2.search(24)<<endl;

    SLL obj3;

    obj3 = obj2;

    cout<<obj3.search(24);
}