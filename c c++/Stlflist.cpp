#include<iostream>
#include<forward_list>
using namespace std;

int main(){

    forward_list<int> fl1;

    fl1.emplace_front(23);
    fl1.emplace_front(64);
    fl1.emplace_front(83);
    fl1.emplace_front(27);
    fl1.emplace_front(84);

    for(auto x : fl1){

        cout<<x<<endl;
    }
}