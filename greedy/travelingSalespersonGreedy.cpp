/*
goal : To find minimum dist req to go to all nodes and come back agian to source node
using Greedy approch
time - O(n^2)
*/
#include <iostream>
#include <limits>
using namespace std;

#define V 4
#define INFINITE 9999

int travelingsalesman(int G[V][V], int source)
{
    int current = source;
    int visited[V] = {0};
    int cost = 0;
    cout << current + 1 << " ";

    visited[current] = 1;

    for (int i = 0; i < V-1; i++)
    {
        int min = INFINITE;
        int nearest = -1;

        for (int j = 0; j < V; j++)
        {
            if (G[current][j] != min && !visited[j])
            {
                if (G[current][j] < min)
                {
                    min = G[current][j];
                    nearest = j;
                }
            }
        }

        if (nearest != -1)
        {
            visited[nearest] = 1;
            cost += min;
            cout << nearest + 1 << " ";

            current = nearest;
        }
    }
    cost += G[current][source];
    cout << source + 1 << endl;

    return cost;
}

int main()
{
    int G[][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    cout << travelingsalesman(G, 0);

    return 0;
}
