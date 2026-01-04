#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s1;

    s1.push(4);
    s1.push(56);

    // s1.pop();

    cout<<s1.top();
}