#include<iostream>
#include<set>
using namespace std;

class functor{

    public:

        bool operator()(const int &a,const int &b)const{

            if(a>b){

                return true;
            }
            else{

                return false;
            }
        }
};

int main(){

    set<int,functor> s1;

    s1 = {234,345,358,265};

    for(auto x : s1){

        cout<<x<<endl;
    }
}