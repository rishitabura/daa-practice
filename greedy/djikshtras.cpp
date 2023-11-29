#include <iostream>
using namespace std;
#define V 6
#define INFINITE 9999

void dijkshtras(int G[V][V], int source)
{
    int mincost = 0;
    int ne = 0;
    int min_index, min;

    int weight[V], visited[V];

    for (int i = 0; i < V; i++)
    {
        weight[i] = INFINITE;
        visited[i] = 0;
    }

    weight[source] = 0;
    while (ne < V - 1)
    {
        min = INFINITE;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && weight[i] <= min)
            {
                min = weight[i];
                min_index = i;
            }
        }
        visited[min_index] = 1;

        for (int j = 0; j < V; j++)
        {
            if (G[min_index][j] != 0 && !visited[j])
            {
                if (G[min_index][j] < weight[j])
                {
                    weight[j] = weight[min_index] + G[min_index][j];
                }
            }
        }

        ne++;
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t" << weight[i] << endl;
    }
}
int main()
{
    int G[V][V] = {
        {0, 5, 0, 3, 0, 6},
        {5, 0, 2, 0, 0, 0},
        {0, 2, 0, 7, 0, 0},
        {3, 0, 7, 0, 4, 0},
        {0, 0, 0, 4, 0, 9},
        {6, 0, 0, 0, 9, 0}};

    dijkshtras(G, 1);

    return 0;
}