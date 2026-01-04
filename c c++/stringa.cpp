#include<iostream>
#include<string>
using namespace std;

int main(){

    string str = "Ankur";

    // for(int i = 0; i<str.size(); i++){

    //     cout<<int(str[i])<<" ";
    // }

    for(char c: str){

        cout<<int(c)<<" ";
    }
}