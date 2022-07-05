#include <iostream>
#include <math.h>
using namespace std;

#define N 8
#define INF INT_MAX

int shortestDist(int graph[N][N]){
    int distance[N]; // Defining the distance of the vertices

    distance[N-1] = 0;

    for(int i = N-2; ~i; --i){
        distance[i] = INF; // Distance array that has no direct connection equals to INF


        for(int j = i; j < N ; ++j){
            if(graph[i][j] == INF)  
                continue;
            distance[i] = min(distance[i], graph[i][j] + distance[j]); // minimum value of cost and distance in comparison
        }
             
    }

   return distance[0];

};

int main()
{
    // Graph stored in the form of an
    // adjacency Matrix
    int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
 
    cout << shortestDist(graph);
    return 0;
}
