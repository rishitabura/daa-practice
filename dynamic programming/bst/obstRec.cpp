/*
The the cost of optimal binary search tree if freq of each key is given
Using Recursion
time = O(2^n)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int freqSum(int freq[], int i, int j)
{
    int sum = 0;
    for (int k = i; k <= j; k++)
    {
        sum += freq[k];
    }
    return sum;
}
int obstRec(int key[], int freq[], int i, int n)
{
    if (n < i)
    {
        return 0;
    }

    if (i == n)
    {
        return freq[i];
    }
    
    int fsum = freqSum(freq, i, n);

    int min = INT_MAX;
    int cost;

    for (int k = i; k <= n; ++k)
    {
        cost = obstRec(key, freq, i, k - 1) + obstRec(key, freq, k+1, n) + fsum;
        if (min > cost)
        {
            min = cost;
        }
    }

    return min;
}
int main()
{
    int key[] = {10, 12,20};
    int freq[] = {34,8,50};
    int n = sizeof(key) / sizeof(int);
    // cout << n << endl; 
    cout << obstRec(key, freq, 0, n-1);
    return 0;
}