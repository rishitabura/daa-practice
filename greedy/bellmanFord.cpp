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

    int graph[][3] = {{0, 2, 6}, {0, 3, 5}, 
                      {0, 2, 5}, {1, 4, -1}, 
                      {2, 1, -2}, {2, 4, 1}, 
                      {3, 2, -2}, {3, 5, -1}, 
                      {4, 6, 3}, {5, 6, 3}

    };

    shortestpath(graph, 0);
    return 0;
}