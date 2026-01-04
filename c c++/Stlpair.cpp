#include<iostream>
#include<utility>
#include<vector>
#include<string>
using namespace std;

int main(){

    vector<int> v1= {234,456,867,24};

    string n1 = "fdsf";

    pair<vector<int>, string> p1;

    p1 = make_pair(v1,n1);

    for(auto x: p1.first){

        cout<<x<<endl;
    }
    cout<<p1.second;
}