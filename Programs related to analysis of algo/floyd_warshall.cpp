// C++ Program for Floyd Warshall Algorithm

#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph
#define V 4
#define INF 99999
 
// A function to print the solution matrix
void printSolution(int dist[][V]);

void floydWarshall(int graph[][V])
{
    
    int dist[V][V], i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                
                if(i==j)
                dist[i][j]=0;
                
                else
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
 
    // Print the shortest distance matrix
    printSolution(dist);
}
 
/* A utility function to print solution */
void printSolution(int dist[][V])
{
    cout << "The shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"<< " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
 
// Driver code
int main()
{
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    // Print the solution
    floydWarshall(graph);
    return 0;
}

