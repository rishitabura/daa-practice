/*
Without using dp
time = O(2^n)
*/

#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}
int main()
{
    cout << fib(5);
    return 0;
}