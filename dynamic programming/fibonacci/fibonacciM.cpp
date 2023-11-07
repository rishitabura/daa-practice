/*
time and number of calls is reduced if we use dp
time = O(n)
using memoization (recursion)
*/

#include <iostream>
using namespace std;

int fibM(int n)
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
        f[i] = fibM(n - 2) + fibM(n - 1);
    }
    return f[n];
}
int main()
{
    cout << fibM(4);
    return 0;
}