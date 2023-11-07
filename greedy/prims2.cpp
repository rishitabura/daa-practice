/*
*/
#include <iostream>
#include <climits>
using namespace std;

#define V 6


int prims2(int G[V][V])
{
    int parent[V], weight[V], visited[V];
    int ne = 0;

    // int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = 0;
    }

    weight[0] = 0;
    parent[0] = -1;

    while (ne < V - 1)
    {
        int min = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && weight[i] < min)
            {
                min = weight[i];
                min_index = i;
            }
        }

        visited[min_index] = 1;

        for (int j = 0; j < V; j++)
        {
            if (G[min_index][j] != 0 && !visited[j] )
            {
                if (G[min_index][j] < weight[j])
                {
                    parent[j] = min_index;
                    weight[j] = G[min_index][j];
                }
            }
            // visited[j] = 1;
        }

        ne++;
    }
    int mincost = 0;
    for (int i = 1; i < V; i++)
    {
        mincost += G[i][parent[i]];
        cout << "Edge (" << parent[i] << "," << i << ") : " << G[i][parent[i]] << endl;
    }

    return mincost;

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

    int source = 1;

    cout << "Minimum cost: " << prims2(G);

    return 0;
}
