#include<iostream>
using namespace std;

struct node{

    node* left;
    int item;
    node* right;
};

class Tree{

    node* root;

    public:
        
        Tree();
        void insertItem(int);
        void deleteItem(int);
        void editItem(int,int);
        node* getRoot();
};

Tree::Tree(){

    root = NULL;

}

void Tree::insertItem(int data){

    if(root==NULL){

        node* n = new node;
        n->item = data;
        n->left = NULL;
        n->right = NULL;

        root = n;
    }
    else{

        node* t = root;

        while(true){

            if(t->item==data){

                cout<<"Already exist"<<endl;
                return;
            }

            if(t->item>data){

                if(t->left==NULL){

                    node* n = new node;
                    n->left = NULL;
                    n->right = NULL;
                    n->item = data;
                    t->left = n;
                    return;
                }

                t = t->left;
            }


            if(t->item<data){

                if(t->right==NULL){

                    node* n = new node;
                    n->left = NULL;
                    n->right = NULL;
                    n->item = data;
                    t->right = n;
                    return;
                }

                t = t->right;
            }
        }
    }
}

void Tree::deleteItem(int data){

    if(root == NULL){
        cout << "Tree is Empty" << endl;
        return;
    }

    node* t = root;

    if(t->item == data){

        node* n = root;

        if(n->right == NULL){
            root = n->left;
            delete n;
            return;
        }

        root = n->right;

        node* temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }

        temp->left = n->left;

        delete n;
        return;
    }

    while(true){

        if(t->item > data && t->left != NULL){

            if(t->left->item == data){

                node* n = t->left;

                t->left = n->right;

                if(n->left != NULL){

                    if(t->left == NULL){
                        t->left = n->left;
                    }
                    else{
                        node* temp = t->left;
                        while(temp->left != NULL)
                            temp = temp->left;

                        temp->left = n->left;
                    }
                }


                delete n;
                return;
            }

            t = t->left;
        }

        else if(t->item < data && t->right != NULL){

            if(t->right->item == data){

                node* n = t->right;

                t->right = n->right;

            if(n->left != NULL){

                if(t->right == NULL){
                    t->right = n->left;
                }
                else{
                    node* temp = t->right;
                    while(temp->left != NULL)
                        temp = temp->left;

                    temp->left = n->left;
                }
            }


                delete n;
                return;
            }

            t = t->right;
        }

        else{
            cout << data << " is not in the tree" << endl;
            return;
        }
    }
}

node* Tree::getRoot(){

    return root;
}

int main(){

    Tree obj;

    obj.insertItem(18);
    obj.insertItem(10);
    obj.insertItem(20);
    obj.insertItem(15);
    obj.insertItem(13);
    obj.deleteItem(30);

    node* root = obj.getRoot();

    return 1;
}