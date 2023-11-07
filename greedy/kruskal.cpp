/*
Time = O(E log E + V log V)
*/
#include <iostream>
#include <climits>
using namespace std;
#define V 4

int parent[V];

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}


int kruskal(int G[][V])
{

    int ne = 0;
    int mincost = 0;
    int a, b, u, v;

    while (ne < V-1)
    {
        int min = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (G[i][j] < min && G[i][j] != 0)
                {
                    min = G[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            cout << "Edge (" << a  << "," << b  << ") : " << min << endl; // printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
            ne++;
        }
        G[a][b] = G[b][a] = 0;
    }
    return mincost;
}
int main()
{
    // int G[][V] = {
    //     {0, 5, 0, 3, 0, 6},
    //     {5, 0, 2, 0, 0, 0},
    //     {0, 2, 0, 7, 0, 0},
    //     {3, 0, 7, 0, 4, 0},
    //     {0, 0, 0, 4, 0, 9},
    //     {6, 0, 0, 0, 9, 0}};
    int G[][V] = {{0, 10, 15, 20},
                  {10, 0, 35, 25},
                  {15, 35, 0, 30},
                  {20, 25, 30, 0}};

    cout << "Minimum cost: " << kruskal(G);

    return 0;
}