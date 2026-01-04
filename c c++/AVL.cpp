#include<iostream>
using namespace std;

struct node{

    int item;
    node* right;
    node* left;
    int height;
};

class AVL{

    

    public:
        node* root;
        AVL();
        void insert(int);

};

AVL::AVL(){

    root = NULL;
}

void AVL::insert(int data){

    if(root==NULL){

        node* n = new node;
        n->item = data;
        n->left = NULL;
        n->right = NULL;
        root = n;
    }
    else{

        node* ptr = root;
        bool flag = true;

        while(flag){

            if(ptr->item==data){

                break;
            }

            if(ptr->item<data){

                if(ptr->right==NULL){

                    node* n = new node;
                    n->item = data;
                    n->left = NULL;
                    n->right = NULL;
                    ptr->right = n;
                    flag = false;
                }
                else{

                    ptr = ptr->right;
                }
            }
            else{

                if(ptr->left==NULL){

                    node* n = new node;
                    n->item = data;
                    n->left = NULL;
                    n->right = NULL;
                    ptr->left = n;
                    flag = false;
                }
                else{

                    ptr = ptr->left;
                }
            }
        }
    }
}

int main(){

    AVL obj1;

    obj1.insert(23);
    obj1.insert(21);
    obj1.insert(30);
    obj1.insert(51);
    obj1.insert(56);
    obj1.insert(12);

    cout<<obj1.root->left->left->item<<"\n"<<obj1.root->left->item<<"\n"<<obj1.root->item<<"\n"<<obj1.root->right->item<<"\n"<<obj1.root->right->right->item<<"\n"<<obj1.root->right->right->right->item;
}