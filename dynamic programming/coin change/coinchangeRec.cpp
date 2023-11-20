/*
not
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int coinChangeCount(int coins[], int sum, int index)
{
    if (index == 0)
    {
        return (sum % coins[0]);
    }

    int notTake = coinChangeCount(coins, sum, index - 1);
    int take = 0;

    if (coins[index] <= sum)
    {
        take = coinChangeCount(coins, sum - coins[index], index);
    }

    // include +  not include
    return take + notTake;
}

int main()
{
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;

    cout << coinChangeCount(coins, sum, n);

    return 0;
}