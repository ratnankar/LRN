#include<iostream>
using namespace std;

class Car{

    public:
        void wheel(){


        }

    protected:
        void cylinder(){


        }

};

class Sportscar: public Car{

    public:
        void nitrogen(){

            cylinder();

        }

};

int main(){

    Sportscar C1;

    C1.wheel();

}