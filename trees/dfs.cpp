#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void addEdge(int a, int b)
{
    adj[a][b] = adj[b][a] = 1;
}

void dfs(int source, vector<bool> &visited)
{

    cout << source << " ";
    visited[source] = true;

    for (int i = 0; i < adj[source].size(); i++)
    {
        if (adj[source][i] == 1 && visited[i] == false)
        {
            dfs(i, visited);
        }
    }
}

int main()
{

    int v = 5;
    vector<bool> visited(v, false);
    adj = vector<vector<int>>(v, vector<int>(v, 0));

    addEdge(0, 4);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(3, 1);

    dfs(0, visited);
    return 0;
}