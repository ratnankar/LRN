#include<iostream>
#include<list>
using namespace std;

int main(){

    list<int> l1;

    l1 = {34,63,63,46};

    // for(auto x: l1){

    //     cout<<x<<endl;
    // }

    list<int>::iterator it;

    for(it = l1.begin(); it!=l1.end(); it++){

        cout<<*it<<endl;
    }
}