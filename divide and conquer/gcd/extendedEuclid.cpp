#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int extendedEuclid(int m, int n, int *x, int *y)
{
    if (m == 0)
    {
        *x = 0;
        *y = 1;
        return n;
    }
    int x1, y1;
    int gcd = extendedEuclid(n%m, m, &x1, &y1);
    *x = y1 - (n / m) * x1;
    *y = x1;

    return gcd;
}
int main()
{
    int x, y, a = 12, b = 21;
    int g = extendedEuclid(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b
         << ") = " << g << endl;
    return 0;
}