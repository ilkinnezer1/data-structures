#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> myPair;

class Graph{
    int Nvertices; // Number of vertices
    list<pair<int, int> > *adjList; //  Storing vertex and weight
public:
    explicit Graph(int vertices);  // Constructor;
    void addEdge(int u, int v, int w); // edges, vertices. weight
    void findShortestPath(int s); // S = Start vertex
};

Graph::Graph(int vertices) {
    this->Nvertices=vertices;
    adjList =  new list<myPair>[Nvertices];
}

void Graph::addEdge(int u, int v, int w) {
    adjList[u].push_back(make_pair(v,w));
    adjList[v].push_back(make_pair(u,w));
}

void Graph::findShortestPath(int startVertex) {
   priority_queue< myPair, vector<myPair>, greater<myPair> > myPq;

   vector<int> distance(Nvertices, INF);
   // Initialization
   myPq.push(make_pair(0, startVertex));
   distance[startVertex] = 0;

   while(!myPq.empty()){
       int u = myPq.top().second;
       myPq.pop();

       list< pair<int, int> > :: iterator itr;

       for(itr = adjList[u].begin(); itr != adjList[u].end(); ++itr){
           int v = (*itr).first;
           int weight = (*itr).second;

           if(distance[v] >= distance[u] + weight){
               distance[v] = distance[u] + weight; //  Relaxation
               myPq.push(make_pair(distance[v], v));
           }
       }
   }

   cout << "Vertex distance from start index: ";
    for (int i = 0; i < Nvertices; ++i)
        printf("%d \t\t %d\n", i, distance[i]);

    cout << endl;
}


int main() {
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.findShortestPath(0);
}

