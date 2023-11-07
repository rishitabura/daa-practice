/*
to find binomail expression 
nCr = n-1Cr-1 + n-1Cr

time and number of calls is reduced if we use dp
time = O(n)
using memoization (recursion)
*/

#include<iostream>
using namespace std;


int binomialM(int n , int r)
{
    if (r ==0 || r == n)
    {
        return 1;
    }
    int f[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 1;
        f[i][i] = 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = binomialM(n-1,r-1) + binomialM(n-1,r);
        }
        
    }
    return f[n][r];
    
}

int main()
{
    cout << binomialM(6,2);
    return 0;
}
