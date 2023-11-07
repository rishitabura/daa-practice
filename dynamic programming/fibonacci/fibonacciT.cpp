/*
time and number of calls is reduced if we use dp
time = O(n)
using tabulation (iteration)
*/

#include <iostream>
using namespace std;

int fibT(int n)
{
    int f[n + 1] = {-1};
    if (n <= 1)
    {
        return n;
    }

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 2] + f[i - 1];
    }
    return f[n];
}

int main()
{
    cout << fibT(4);
    return 0;
}