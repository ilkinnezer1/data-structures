#include <iostream>
using namespace std;

// Struct the edge
struct Edge{
    int src, destination, weight;
};
// Struct the graph
struct Graph{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void BellmanFord(struct Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;
    int distance[V];

    for(int i=0; i<V; i++){
        distance[i] = INT_MAX;
        distance[src] = 0;
    }
    for(int i=1; i < V - 1; ++i){
        for(int j =0; j < E; ++j){
            int u = graph->edge[j].src; // source
            int v = graph->edge[j].destination; // destination
            int weight = graph->edge[j].weight; //weight
            if(distance[u] != INT_MAX && distance[u] + weight < distance[v]){
                // Relaxation
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Negative cycle detection
    for(int i =0; i<E; ++i){
        int u = graph->edge[i].src;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if(distance[u] != INT_MAX &&  distance[v] > distance[u] + weight){
            cout << "Grapht contains negative weight cycle" <<endl;
            return;
        }
    }
      cout << "Vertex :/t/t/t";
   for (int i = 0; i < V; ++i)
      printf("%d \t", i);
      printf("\nDistance From Source : ");
   for (int i = 0; i < V; ++i)
      printf("%d \t",distance[i]);
   return;
}
int main() {
    int V = 5;
    int E = 8;
    struct Graph *graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = -1;
    graph->edge[1].src = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 4;
    graph->edge[2].src = 1;
    graph->edge[2].destination = 2;
    graph->edge[2].weight = 3;
    graph->edge[3].src = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 2;
    graph->edge[4].src = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = 2;
    graph->edge[5].src = 3;
    graph->edge[5].destination = 2;
    graph->edge[5].weight = 5;
    graph->edge[6].src = 3;
    graph->edge[6].destination = 1;
    graph->edge[6].weight = 1;
    graph->edge[7].src = 4;
    graph->edge[7].destination = 3;
    graph->edge[7].weight = -3;
    BellmanFord(graph, 0);
    return 0;

}