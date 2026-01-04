#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

int main(){

    int e = 23;
    string str = "dgsf";
    vector<double> v1 = {434.35,32423.53,54235.3534};

    tuple<int,string,vector<double>> t1;

    t1 = make_tuple(e,str,v1);

    cout<<get<0>(t1)<<endl<<get<1>(t1)<<endl;

    for(auto x : get<2>(t1)){

        cout<<x<<endl;
    }
}