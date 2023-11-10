/*
goal: The task is to put the items into the bag such that the sum of profits associated with them is the maximum possible
using tabulation (bottom up approch
time - O(n*m)
space - O(n*m)
*/

#include <iostream>
using namespace std;

int knapsackDP(int p[], int wt[], int m, int n)
{
    int k[n + 1][m + 1];

    int i, w;
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                k[i][w] = max(k[i - 1][w - wt[i - 1]] + p[i - 1], k[i - 1][w]);
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
    int o = n;
    int wo = m;

    // cout << o << wo<< endl;
    while (o >= 0 && wo >= 0)
    {

        if (k[o][wo] == k[o - 1][wo])
        {
            cout << o << " = 0" << endl;
            o--;
        }
        else
        {
            cout << o << " = 1" << endl;
            o--;
            wo = wo - wt[o];
        }
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