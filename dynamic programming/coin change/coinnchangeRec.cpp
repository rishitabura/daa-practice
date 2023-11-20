/*
goal : find the total number of ways or coins equal to the sum
using recursion
include or not include
time - O(2^sum)
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int coinChangeCount(int coins[], int sum, int n)
{
    if(sum == 0)
    {
        return 1;
    }
    if(n == 0  || sum < 0)
    {
        return 0;
    }   

    // include +  not include
    return coinChangeCount(coins,sum-coins[n-1], n) + coinChangeCount(coins, sum, n-1);
}

int main()
{
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 5;

    cout << coinChangeCount(coins, sum, n);

    return 0;
}