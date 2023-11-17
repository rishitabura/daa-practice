/*
we decide if the object to be included or not
try out all the posiibilities and consider all subsets of items and calculate the total weight and profit of all subsets.
time - O(2^n)
space - O(n)
*/

#include <iostream>
using namespace std;


int knapsackRec(int p[], int wt[], int m , int n)
{
    // int k[n+1][m+1];
    if (n == 0 || m==0)
    {
        return 0;
    }

    // not include
    if (wt[n-1] > m)
    {
        return knapsackRec(p,wt,m,n-1);
    }

    // include
    else
    {
        return max(p[n-1] + knapsackRec(p,wt,m-wt[n-1], n-1) , knapsackRec(p,wt,m,n-1) );
    }
    
}

int main()
{
    int p[] = {1, 2, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int m = 8;
    int n = sizeof(p) / sizeof(int);

    cout << knapsackRec(p, wt, m, n);
    return 0;
}