#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include <climits>
using namespace std;

struct node{

    int vertex;
    int weight;
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

        void addEdge(int u, int v, int w){

            node* n = createNode(v);

            n->weight = w;
            n->next = adj[u];
            adj[u] = n;

            n = createNode(u);

            n->weight = w;
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

        int weight(int u, int v){

            node* w = adj[u];

            while(w->vertex != v){

                w = w->next;
            }

            return w->weight;
        }

        void dijkstra(int u){

            queue<int> q;

            int d[6];
            int PAR[6];

            for(int i = 0; i < 6; i++){

                d[i] = INT_MAX;
                PAR[i] = -1;
            }

            d[u] = 0;
            PAR[u] = u;

            for(int i = 0; i<Vertices; i++){

                q.push(i);
            }

            while(!q.empty()){

                relax(q.front(), d, PAR);
                q.pop();
            }

            for(int i = 0; i<Vertices; i++){

                cout<<u<<" -> ";

                if(PAR[i]!=u){

                    int t = PAR[i];
                    stack<int> p;

                    while(t!=u){

                        p.push(t);
                        t = PAR[t];
                    }

                    while(p.size()){

                        if(p.size()==1){

                            cout<<p.top()<<" -> "<<i<<" = ";
                            p.pop();

                        }
                        else{

                            cout<<p.top()<<" -> ";
                            p.pop();
                        }
                    }

                    cout<<d[i];
                }
                else{

                    cout<<i<<" = "<<d[i];
                }

                cout<<endl;
            }
        }
        
        void relax(int u,int (&d)[6], int (&PAR)[6]){

            node* n = adj[u];

            while(n){

                if(d[n->vertex]>d[u]+weight(u,n->vertex)){

                    d[n->vertex]=d[u]+weight(u,n->vertex);

                    PAR[n->vertex] = u;
                }

                n= n->next;
            }
        }
};

int main(){


    Graph obj(6);

    obj.addEdge(0,1,15);
    obj.addEdge(0,2,15);
    obj.addEdge(1,2,25);
    obj.addEdge(1,3,30);
    obj.addEdge(4,5,25);
    obj.addEdge(5,3,20);
    obj.addEdge(2,3,10);
    obj.addEdge(1,4,40);

    obj.dijkstra(0);
}