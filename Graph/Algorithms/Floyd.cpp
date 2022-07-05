#include <iostream>
using namespace std;

// Steps to solve the problem
// 1. Define the infinity and the size of matrices
// 2. Initialize distance matrix
// 3. Find SP without intermediate vertex
// 4. Chech whether taking distance[i][j] is greater than other path
// 5. Print the matrices with SP

#define V 2
#define INF INT_MAX

void print(int distance[][V]); //  the solution of matrices

void shortest_distance(int graph[][V]){
    // Output matrices
    
    int distance[V][V]; // define the distance matrix
    
    for(int i = 0; i < V; ++i){
        for(int j=0; j <V; ++j){
            distance[i][j] = graph[i][j]; // No intermediate vertex
        }
    } 
    // If there is an intermediate vertex
    for(int k =0 ; k<V; ++k){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){

                if(distance[i][j] > distance[i][k] + distance[k][j] &&
                   distance[k][j] !=INF && distance[i][k] != INF){
                       // take the small value
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    print(distance);
}










void print(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    floyd(graph);
    return 0;
}
