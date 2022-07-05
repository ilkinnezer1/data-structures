#include <iostream>
#include <list>
using namespace std;

class Graph{
    int Nvertices;
    list<int> *adjList;
    bool *visited;

public:
    explicit Graph(int vertices);
    void addEdge(int index, int destination);
    void DFS(int vertex);
};

Graph::Graph(int vertices) {
    Nvertices = vertices;
    adjList = new list<int>[vertices];
    visited = new bool[vertices];
}
void Graph::addEdge(int index, int destination) {
    adjList[index].push_back(destination);
}

void Graph::DFS(int vertex) {
    visited[vertex] = true; // make vertex visited
    list<int>stack = adjList[vertex];
    cout << vertex << " ";

    for(int adjVertex : stack){
        if(!visited[adjVertex]){
            DFS(adjVertex);
        }
    }

}
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.DFS(2);

    return 0;
}

