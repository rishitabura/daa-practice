/*
The the cost of optimal binary search tree if freq of each key is given
Using Bottom up approch
time = O(n^3)
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define MAX 10000
int freqSum(int freq[], int i, int n)
{
    int sum = 0;
    for (int k = i; k <= n; k++)
    {
        sum += freq[k];
    }
    return sum;
}

// int C[MAX][MAX];

int obstM(int key[], int freq[], int i, int n, vector<vector<int>> &dp)
{
    if(i > n)
    {
        return 0;
    }
    if (dp[i][n])
    {
        return dp[i][n];
    }

    int fsum = freqSum(freq, i, n);

    int min = INT_MAX;
    for (int k = i; k <= n; ++k)
    {
        int cost = obstM(key, freq, i, k - 1, dp) + obstM(key, freq, k + 1, n, dp) + fsum;

        if (min > cost)
        {
            min = cost;
            dp[i][n] = cost;
        }
    }

    return dp[i][n];
}
int main()
{
    int key[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(key) / sizeof(int);
    vector<vector<int >> dp(n+1, vector<int>(n+1,0));
    cout << obstM(key, freq, 0, n - 1, dp);

    return 0;
}