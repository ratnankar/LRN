#include <iostream>
using namespace std;

struct node {

    int item;
    node* left;
    node* right;
};

class BST{

    private:
        node* root;
        node* ptr;

    public:
        BST();
        bool isEmpty();
        void insert(int);
        void preorder();
        void inorder();
        void postorder();
        void recPreorder(node*);
        void recInorder(node*);
        void recPostorder(node*);
        node* search(int);
        void deleteI(int);
};

BST::BST(){

    root = NULL;
}

bool BST::isEmpty(){

    return root==NULL;
}

void BST::insert(int data){

    if(root==NULL){

        node* n = new node;
        n->left = NULL;
        n->item = data;
        n->right = NULL;
        root = n;
    }
    else{

        node* ptr = root;
        bool flag = true;

        while(flag){

            if(data==ptr->item){

                break;
            }

            if(data<ptr->item){

                if(ptr->left==NULL){

                    node* n = new node;
                    n->left = NULL;
                    n->item = data;
                    n->right = NULL;
                    ptr->left = n;
                    flag = false;
                }
                else{

                    ptr = ptr->left;
                }
            }
            else{

                if(ptr->right==NULL){

                    node* n = new node;
                    n->left = NULL;
                    n->item = data;
                    n->right = NULL;
                    ptr->right = n;
                    flag = false;
                }
                else{

                    ptr = ptr->right;
                }
            }
        }
    }
}

void BST::recPreorder(node* ptr){

    if(ptr){

        cout<<ptr->item<<" ";
        recPreorder(ptr->left);
        recPreorder(ptr->right);
    }
}

void BST::recInorder(node* ptr){

    if(ptr){

        recPreorder(ptr->left);
        cout<<ptr->item<<" ";
        recPreorder(ptr->right);
    }
}

void BST::recPostorder(node* ptr){

    if(ptr){

        recPreorder(ptr->left);
        recPreorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}

void BST::preorder(){

    recPreorder(root);
}

void BST::inorder(){

    recInorder(root);
}

void BST::postorder(){

    recPostorder(root);
}

node* BST::search(int data){

    node* ptr = root;

    while(ptr){

        if(ptr->item==data){

            return ptr;
        }

        if(ptr->item>data){

            ptr = ptr->left;
        }
        else{

            ptr = ptr->right;
        }
    }
    return NULL;
}

// void BST::deleteI(int data){

//     node* d = search(data);

//     node* e = d->left;
//     node* f = d->right;

//     d->item = d->right->item;
//     d->left = d->right->left;
//     d->right = d->right->right;

//     delete f;

//     node* g = d;

//     while(g->left!=NULL){

//         g = g->left;
//     }

//     g->left = e;
// }

void BST::deleteI(int data){

    node* ptr = root;
    node* ptptr = NULL;

    if(ptr->item==data){


    }
    else{

        while(ptr){

        if(ptr->item>data){

            ptptr = ptr;
            ptr = ptr->left;
            if(ptr->item==data){

                break;
            }
        }
        else{

            ptptr = ptr;
            ptr = ptr->right;
            if(ptr->item==data){

                break;
            }
        }
    }

        if(root->item>data){

            if(ptr->left&&ptr->right){

                if(ptptr->item<data){

                    ptptr->right = ptr->right;
                }
                else{

                    ptptr->left = ptr->right;
                }

                node* a = ptr->left;

                while(a->left){

                    a = a->left;
                }

                a->left = ptr->left;

                delete ptr;
            }
            if(ptr->left==NULL){

                if(ptptr->item<data){

                    ptptr->right = ptr->right;
                }
                else{

                    ptptr->left = ptr->right;
                }

                delete ptr;
            }
            if(ptr->right==NULL){

                if(ptptr->item<data){

                    ptptr->right = ptr->left;
                }
                else{

                    ptptr->left = ptr->left;
                }

                delete ptr;
            }
            if(ptr->right==NULL&&ptr->left==NULL){

                delete ptr;

                if(ptptr->item<data){

                    ptptr->right = NULL;
                }
                else{

                    ptptr->left = NULL;
                }
            }
        }
        else{

            if(ptr->left&&ptr->right){

                if(ptptr->item<data){

                    ptptr->right = ptr->right;
                }
                else{

                    ptptr->left = ptr->right;
                }

                node* a = ptr->left;

                while(a->left){

                    a = a->left;
                }

                a->left = ptr->left;

                delete ptr;
            }
            if(ptr->left==NULL){

                if(ptptr->item<data){

                    ptptr->right = ptr->right;
                }
                else{

                    ptptr->left = ptr->right;
                }

                delete ptr;
            }
            if(ptr->right==NULL){

                if(ptptr->item<data){

                    ptptr->right = ptr->left;
                }
                else{

                    ptptr->left = ptr->left;
                }

                delete ptr;
            }
            if(ptr->right==NULL&&ptr->left==NULL){

                delete ptr;

                if(ptptr->item<data){

                    ptptr->right = NULL;
                }
                else{

                    ptptr->left = NULL;
                }
            }
        }
    }
}

int main(){

    BST t1;

    t1.insert(50);
    t1.insert(30);
    t1.insert(70);
    t1.insert(10);
    t1.insert(60);
    t1.insert(90);
    t1.insert(20);
    t1.insert(80);
    t1.insert(15);
    t1.insert(25);
    t1.insert(75);
    t1.insert(85);

    t1.deleteI(80);

    t1.inorder();
}