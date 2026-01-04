#include<iostream>
#include<queue>
using namespace std;

class Emp{

    public:

        string emp_name;
        int salary;

        Emp(string we, int sal):emp_name(we),salary(sal){}

        int getsal(){

            return salary;
        }
};

class compsal{

    public:

        bool operator()(Emp &e,Emp &e1){

            return e.getsal()<e1.getsal();
        }

};

int main(){

    priority_queue<int> pq1;
    priority_queue<Emp,vector<Emp>,compsal> pq2;

    pq1.push(235);
    pq1.push(452);
    pq1.push(893);
    pq1.push(452);
    pq1.push(792);

    pq2.push({"Ankur", 5000});
    pq2.push({"Mohan", 8000});
    pq2.push({"Sohan", 3000});

    cout<<pq2.top().emp_name;
}