#include<iostream>
using namespace std;

class Graph{

    int V;
    int adj[10][10];

    public:

        Graph(int vertices){

            V = vertices;

            for(int i = 0; i<vertices; i++){

                for(int j = 0; j<vertices;j++){

                    adj[i][j] = 0;
                }
            }
        }

        void display() {

            cout << "Adjacency Matrix:\n";

            for (int i = 0; i < V; i++) {

                for (int j = 0; j < V; j++) {

                    cout << adj[i][j] << " ";
                }

                cout << endl;
            }
        }
};

int main(){

    Graph obj(10);

    obj.display();

}