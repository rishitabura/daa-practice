#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int V = 4;  // Number of cities

int tsp(int n, int G[][V]) {
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    // Base case: Starting from any city to itself with an empty set of cities visited
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue;

            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j) && i != j) {
                    dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + G[j][i]);
                }
            }
        }
    }

    int finalMask = (1 << n) - 1;
    int minCost = INF;
    for (int i = 0; i < n; ++i) {
        if (dp[finalMask][i] != INF) {
            minCost = min(minCost, dp[finalMask][i] + G[i][0]);
        }
    }

    return minCost;
}

int main() {
    int G[][V] = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    int minCost = tsp(V, G);

    cout << "Minimum cost of the TSP: " << minCost << endl;

    return 0;
}
