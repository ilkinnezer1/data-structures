#include <iostream>
using namespace std;

#define V 4

void print(int color[]);

bool isSafeToColor(bool graph[V][V], int color[])
{
    for(int i = 0; i<V; ++i)
        for(int j = i + 1; j<V; ++j)
            if(graph[i][j]&& color[i] == color[j])
                return false;

    return true;
}

bool graphColoring(bool graph[V][V],int m, int i, int color[V] )
{
    if(i == V) // Current index equals end
    {
        if(isSafeToColor(graph, color)){
            print(color);
            return true;
        }
    return false;
}


    for(int j = 1; j <= m; ++j){
        color[i] = j; // Assign color
        if(graphColoring(graph, m, i+1, color))
            return true;
        color[i]=0;
    }

    return false;

    
}

void print(int color[])
{
    cout << "Solution Exists:" " Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
        cout << "  " << color[i];
    cout << "\n";
}

int main()
{
        bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3;
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
 
    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";
}