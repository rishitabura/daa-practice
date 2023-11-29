/*
goal : find the gcd of two numbers given
using brute force
time - O(min(m,n))
space - O(n)
*/

#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    int g = min(m,n);
    while (g>0)
    {
        if (m%g== 0 && n%g ==0)
        {
            // cout << "Hello" << g;
            return g;
        }
        else
        {
            g = g - 1;
        }
    }

    return 1;

}

int main()
{
    int m = 12;
    int n = 33;
    cout << gcd(m, n);
    return 0;
}