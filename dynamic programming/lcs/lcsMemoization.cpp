/*
goal : find the length of longest common subsequence
using memoization (top down approch)
time - O(m*n)  due to two possibilities
space - O(m*n)
*/


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int lcs(char s1[], char s2[], int i, int j, vector<vector<int>> &dp)
{
    if (s1[i] == '\0' || s2 == '\0')
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
    }
    // if (dp[i][j] != -1)
    // {
    //     return dp[i][j];
    // }

    return dp[i][j] = max(lcs(s1, s2, i + 1, j, dp), lcs(s1, s2, i, j + 1, dp));
  
}
int main()
{
    char s1[] = {'b', 'd', '\0'};
    char s2[] = {'a', 'b', 'c', 'd', '\0'};
    int m = strlen(s1);
    int n = strlen(s2);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    cout << lcs(s1, s2, 0, 0, dp) << endl;
    for(int k = 0 ; k<m+1; k++)
    {
        for(int z= 0; z<n+1; z++)
        {
            cout << dp[k][z] << " ";
        }
        cout << endl;
    }

    return 0;
}