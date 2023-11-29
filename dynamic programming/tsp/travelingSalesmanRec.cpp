/*
goal : To find minimum dist req to go to all nodes and come back agian to source node
using Recursion
time - O(n!) - O(n^n)
space - O(n)
*/

#include <iostream>
using namespace std;
#define V 4
#define INFINITE 9999

int visited[V] = {0};
int cost = 0;
void travelingsalesman(int G[V][V], int source)
{

    int adj = INFINITE;
    // int cost = 0;
    int min = INFINITE;

    visited[source] = 1;

    cout << source + 1 << " ";

    for (int i = 0; i < V; i++)
    {
        if (G[source][i] != 0 && !visited[i])
        {
            if (G[source][i] < min)
            {
                min = G[source][i];
                adj = i;
            }
        }
    }
    // cost += min;
    if (min != INFINITE)
    {
        cost = cost + min;
    }
    // cout << "\nCost : " << cost << endl;

    // to return back from last node to first node
    if (adj == INFINITE)
    {
        adj = 0;
        cout << adj + 1;
        cost = cost + G[source][adj];
        // cout << "\nCost : " << cost;
        return;
    }

    travelingsalesman(G, adj);
}
int main()
{
    // int G[][V] = {
    //     {0, 30, 33, 10, 45},
    //     {56, 0, 9, 15, 18},
    //     {29, 13, 0, 5, 12},
    //     {33, 28, 16, 0, 3},
    //     {1, 4, 30, 24, 0}};
    // int G[][V] = {{0, 10, 15, 20},
    //              {10, 0, 35, 25},
    //              {15, 35, 0, 30},
    //              {20, 25, 30, 0}};

    //  int G[][V] = {
    //     { 0, 10, 15, 20 },
    //     { 10, 0, 35, 25 },
    //     { 15, 35, 0, 30 },
    //     { 20, 25, 30, 0 }
    // };
    // int G[][V] = {
    //     {0, 10, 15, 20},
    //     {5, 0, 9, 10},
    //     {6, 13, 0, 12},
    //     {8, 8, 9, 0}
    // };

    int G[][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    travelingsalesman(G, 0);
    cout << "\nCost : " << cost;
    return 0;
}
