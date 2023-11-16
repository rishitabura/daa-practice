/*
goal : find the length of longest common subsequence
using DP (bottom up approch)
time - O(m*n)  due to two possibilities
space - O(m*n)
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int longestCommonSubsequence(string text1, string text2)
{

    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // if (m == 0 || n == 0)
    // {
    //     return 0;
    // }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i== 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // else if(dp[i][j] != 1)
            // {
            //     dp[i][j] = 1+ dp[i][j];
            // }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}
int main()
{
    string s1 = "bd";
    string s2 = "abcd";

    cout << longestCommonSubsequence(s1, s2);
    return 0;
}