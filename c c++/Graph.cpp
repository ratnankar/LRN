#include<iostream>
using namespace std;

struct node{

    int vertex;
    node* next;
};

class Graph{


    public:

    int Vertices;
    node** adj;
        Graph(int v){

            Vertices = v;
            adj = new node*[Vertices];
            
            for(int i = 0; i<Vertices; i++){

                adj[i] = NULL;
            }
        }

        node* createNode(int v){

            node* n = new node;

            n->vertex = v;
            n->next = NULL;

            return n;
        }

        void addEdge(int u, int v){

            node* n = createNode(v);

            n->next = adj[u];
            adj[u] = n;

            n = createNode(u);

            n->next = adj[v];
            adj[v] = n;
        }

        void display() {

            for (int i = 0; i < Vertices; i++) {

                cout << i << " -> ";
                node* temp = adj[i];

                while (temp != NULL) {

                    cout << temp->vertex << " ";
                    temp = temp->next;
                }

                cout << endl;
            }
        }

        void DFS(int start){

            
        }
};

int main(){


    Graph obj(5);

    obj.addEdge(0,1);
    
    obj.display();
}