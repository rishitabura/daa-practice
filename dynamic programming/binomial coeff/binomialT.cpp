/*
to find binomail expression
nCr = n-1Cr-1 + n-1Cr

time and number of calls is reduced if we use dp
time = O(n*r)
using tabulation (iteration)
*/

#include <iostream>
using namespace std;

int binomialT(int n, int r)
{

    int f[n + 1][r + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (j == 0 || j == i)
            {
                f[i][j] = 1;
            }
            else
            {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
            }
        }
    }
    return f[n][r];
}

int main()
{
    cout << binomialT(6, 3);
    return 0;
}
