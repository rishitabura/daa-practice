/*
time and number of calls is reduced if we use dp
time = O(n)
using memoization (recursion)
*/

#include <iostream>
#include <vector>
using namespace std;

int fibM(int n, vector<int> &f)
{
    if (n <= 1)
    {
        return n;
    }
    // f[0] = 0;
    // f[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     f[i] = fibM(n - 2) + fibM(n - 1);
    // }

    if (f[n] != -1)
    {
        return f[n];
    }
    else
    {
        f[n] = fibM(n - 2, f) + fibM(n - 1, f);
    }

    return f[n];
}
int main()
{
    int n = 4;
    vector<int> f (n+1, -1);
    cout << fibM(n , f);
    return 0;
}