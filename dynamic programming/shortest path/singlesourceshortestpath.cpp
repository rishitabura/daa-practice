#include <iostream>
using namespace std;
#define V 7
#define E 10
#define INFINITE 9999

void shortestpath(int C[][3], int source)
{
    int d[V];
    for (int i = 0; i < V; i++)
    {
        d[i] = INFINITE;
    }
    d[source] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (d[C[j][0]] != INFINITE && d[C[j][0]] + C[j][2] < d[C[j][1]])
            {
                d[C[j][1]] = d[C[j][0]] + C[j][2];
            }
        }
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << d[i] << endl;
    }
}
int main()
{
    // int source = 0;
    // int G[V][V] = {
    //     {0, 6, 5, 5, INFINITE, INFINITE, INFINITE},
    //     {INFINITE, 0, -2, INFINITE, -1, INFINITE, INFINITE},
    //     {INFINITE, -2, 0, 1, INFINITE, INFINITE},
    //     {INFINITE, INFINITE, -2, 0, INFINITE, -1, INFINITE},
    //     {INFINITE, INFINITE, INFINITE, INFINITE, 0, INFINITE, 3},
    //     {INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 0, 3},
    //     {INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 0}};

    int graph[][3] = {{0,2,6} , {0,3,5}, {0,2,5},
                      {1,4,-1}, {2,1,-2}, {2,4,1},
                      {3,2,-2}, {3,5,-1}, {4,6,3}, 
                      {5,6,3} 
    
    };
    //  int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
    //                    { 1, 2, 3 }, { 1, 3, 2 }, 
    //                    { 1, 4, 2 }, { 3, 2, 5 }, 
    //                    { 3, 1, 1 }, { 4, 3, -3 } };

    shortestpath(graph,0);
    return 0;
}