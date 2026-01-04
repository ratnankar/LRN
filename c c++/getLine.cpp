#include<iostream>
using namespace std;

class Book{

    private:

        int id;
        char name[20];
        float price;

    public:

        void bookinput(){

            cout<<"Enter the id of the book : ";
            cin>>id;

            cout<<"Enter the name of the book : ";
            cin.ignore();
            cin.getline(name,20);

            cout<<"Enter the price of the book : ";
            cin>>price;

        }

    void displaybook(){

        cout<<"\nId of the book : "<<id
            <<"\nName of the book : "<<name
            <<"\nPrice of the book : "<<price;

    }

};

int main(){

    Book b1;

    b1.bookinput();

    b1.displaybook();

}