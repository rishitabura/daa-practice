/*
goal : find the total number of ways or coins equal to the sum
using memoization
include or not include
time - O(n*sum)
space - O(n*sum)
*/

#include <bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

int coinCount(int coins[], int n , int sum , vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        dp[n][sum] = 1;
    }
    if(n == 0 || sum<0)
    {
        return 0;
    }
    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    return dp[n][sum] = coinCount(coins, n, sum-coins[n-1], dp) + coinCount(coins, n-1 , sum , dp);
    
}

int main()
{
    int coins[] = {1, 5, 10};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 8;
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

    cout << coinCount(coins, n, sum, dp);


    

    return 0;
}