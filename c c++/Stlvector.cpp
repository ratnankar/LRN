#include<iostream>
#include<vector>
using namespace std;

class Student{

    public:

        int data;
        int item;

};

int main(){

    vector<int> v1 = {325,546};

    vector<Student*> v2;
    
    v2.push_back(new Student);

    v2[0]->data = 23;
    
    cout<<v1.size();

}