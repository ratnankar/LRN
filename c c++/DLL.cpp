#include<iostream>
using namespace std;

struct node{

    node* prev;
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


SLL::~SLL(){

    while(start){

        deleteFirst();
    }
}
int main(){


}