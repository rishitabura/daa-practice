/*
using source as first node
Time - O(V^2)
*/

#include <iostream>
using namespace std;

#define V 6
#define INFINITE 99999

int prims(int G[V][V])
{
    int ne = 0, min, mincost = 0;
    int visited[V] = {0};

    // for (int i = 0; i < V; i++)
    // {
    //     visited[i] = 0;
    // }

    int x, y;
    visited[0] = 1;
    while (ne < V - 1)
    {
        min = INFINITE;
        x = 0, y = 0;
        for (int i = 0; i < V; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (G[i][j] != 0 && !visited[j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        visited[y] = 1;
        ne++;
        mincost += min;
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

    cout << prims(G);

    return 0;
}