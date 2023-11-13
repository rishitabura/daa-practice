#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int tsp(int G[]{}, int source) {
    vector<vector<int>> dp(V, vector<int>(V, INT_MAX));

    for (int i = 0; i < V; i++)
    {
        dp[i][i] == 0;
    }
    for(int i = 1; < i<V; ++i)
    {
        for(int j = 0 ; )
    }

    

    
    
   
    return minCost;
}

int main() {
    // Example graph with distances between cities
    int n = 4;  // Number of cities
    vector<vector<int>> graph = {
          {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    int minCost = tsp(n, graph);

    cout << "Minimum cost of the TSP: " << minCost << endl;

    return 0;
}
