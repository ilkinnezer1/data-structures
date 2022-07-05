#include <iostream>
#include <list>
using namespace std;


class Graph{
    int Nvertices;
    list<int>* adjList; // Adjacency list
    bool* visited;  // Visited vertices


public:
    Graph(int vertices);
    void addEdge(int index,  int destination);
    void BFS(int startVertex);
};

Graph::Graph(int vertices) {
    Nvertices = vertices;
    adjList = new list<int>[vertices];

}


void Graph::addEdge(int index, int destination){
    adjList[index].push_back(destination);
    adjList[destination].push_back(index);
}


void Graph::BFS(int startVertex){
    visited = new bool[Nvertices];
    for(int i = 0; i < Nvertices;++i)
        visited[i] = false;

    list<int>queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);


    while(!queue.empty()){
        int currentVertex = queue.front();
        cout << "Visited: "<< currentVertex << " ";
        queue.pop_front();


        for(int adjVertex : adjList[currentVertex]){
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }


        }
    }
}
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}

