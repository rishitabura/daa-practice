#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int knapsackDP(int p[], int wt[], int m, int n)
{
    int k[n + 1][m + 1];
    for (int i = 0; i <= m; i++)
    {
        k[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        k[i][0] = 0;
        for (int w = 1; w <= m; w++)
        {
            if (wt[i] <= w)
            {
                k[i][w] = max(k[i - 1][w], p[i] + k[i - 1][w - wt[i]]);
            }
            else
            {
                k[i][w] = k[i - 1][w];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            cout << k[i][w] << "\t";
        }
        cout << endl;
    }

    return k[n][m];
}
int main()
{
    int p[] = {1, 2, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int m = 8;
    int n = sizeof(p) / sizeof(int);

    cout << knapsackDP(p, wt, m, n);
    return 0;
}