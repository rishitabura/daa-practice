#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void addEdge(int a, int b)
{
    adj[a][b] = adj[b][a] = 1;
}

void bfs(int source)
{
    vector<bool> visited(adj.size(), false);
    vector<int> q;

    q.push_back(source);

    visited[source] = true;
    int vis;

    while (!q.empty())
    {
        vis = q[0];

        cout << vis << " ";
        q.erase(q.begin());

        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && visited[i] == false)
            {
                q.push_back(i);

                visited[i] = true;
            }
        }
    }
}

int main()
{

    int v = 6;

    adj = vector<vector<int>>(v,vector<int>(v,0));

    addEdge(0,4);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(3,1);
    addEdge(4,5);



    bfs(0);
    return 0;
}