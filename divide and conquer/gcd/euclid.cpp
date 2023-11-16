/*
goal : find the gcd of two numbers given
using Euclid method
time - O(log(min(m, n)))
space - O(n)
*/
#include<iostream>
using namespace std;

int gcdEuclids(int m, int n)
{
    if (n%m == 0)
    {
        return m;
    }
    while (m>0)
    {
        int r = n%m;
        return gcdEuclids(r,m);
    }

}
int main()
{
    cout << gcdEuclids(12,21);
    return 0;
}