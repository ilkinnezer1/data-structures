#include <iostream>
#include <cstring>
using namespace std;

#define V 5
#define HIGH 999999


int main()
{
//Graph G=(E,V)
    int G[V][V] = {
        {0,4,0,5,2},
        {4,0,1,3,0},
        {0,1,0,8,0},
        {5,3,8,0,2},
        {2,0,0,2,0}
    };
    //Visited Array
    int visited_array[V];
    memset(visited_array,false, sizeof(visited_array));
    visited_array[0] = true;

    //Edge and Weight of Graph print
    cout << "EDGE : WEIGHT\n" <<  endl;

    //Number of edges
    int numberOfEdges = 0;

while(numberOfEdges < V-1) //E = V-1 based on def of MST
{
    int min = HIGH; //to choose minimum value 
    int row = 0, col = 0;

    for(int i = 0; i < V; i++ ) //For visiting rows in the matrix
    {
        if(visited_array[i]){
                //For visiting columns in the matrix 
            for(int j = 0; j < V; j++){
                if(min > G[i][j]){
                    if(!visited_array[j] && G[i][j]){
                        min = G[i][j];  
                        row = i;
                        col = j; 
                        };
                    };
                };
            };
        };
        cout <<" "<< row << "-" << col <<  " " << G[row][col]<<endl;
        visited_array[col] = true;
        numberOfEdges++;
    };

    return 0;
}


