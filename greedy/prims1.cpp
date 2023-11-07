/*
using any source as first node*/

#include <iostream>
using namespace std;
#define V 6
#define INFINITE 99999

int prims1(int G[V][V], int source)
{
    int ne = 0;
    int min, mincost = 0;
    int visited[V] = {0};

    int x, y;
    visited[source] = 1;
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
        cout << "Edge " << "(" << x << "," <<  y << ") : " << min<< endl; 
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

    int source = 0;

    cout << "Minimum cost: " <<  prims1(G, source);

    return 0;
}