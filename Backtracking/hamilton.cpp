 #include <iostream>
 using namespace std;
 #define V 5

 // Pseudocode 

 //while there exists any untried conflagration
//  {
        // Generate the next vertex
        // if(there is an edge btwn 2 vertices  edge exist btwn last and first vertices
        //, without any duplicate vertex)
        // {
            // Output this configuration
            // break;
        // }
//  } 
// time O(n^n)

void print(int path[]); // Declaration

bool isSafeToCheck(int vertex, bool graph[V][V], int path[], int position)
{
    if(graph[path[position - 1]][vertex] == 0) // check adjacent vertices
        return false;

    // Checking duplicate values
    for(int i = 0; i < position; ++i)
        if(path[i] == vertex)
            return false;
    
    return true;
}

bool cycleDetector(bool graph[V][V], int path[], int position)
{
    //BaseCase
     if(position == V)
        if(graph[path[position - 1]][path[0]] == 1)  // edge last -> first vertex 
            return true;
        else
            return false;

     for(int i = 0; i < V; ++i){
        // Try next vertex
            if(isSafeToCheck(i, graph, path, position)){
                path[position] = i;
                // If there is a cycle
                if(cycleDetector(graph, path, position + 1) == true)    
                    return true;

            
                path[position] = -1; // there is not solution and removing
            }
     }

     return false;
}




bool isCycle(bool graph[V][V])
{
    int *path = new int [V];

    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 1;


    if (cycleDetector(graph, path, 1) == false )
    {
        cout << "Solution does not exist";
        return false;
    }
 
    print (path);
    return true;
}

void print(int path[])
{
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
 
    // Let us print the first vertex again
    // to show the complete cycle
    cout << path[0] << " ";
    cout << endl;
}


int main()
{
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
    isCycle(graph1);
     
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
 
    isCycle(graph2);
}