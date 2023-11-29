/*
goal: find the power a^n = b
using divide and conquer
time - O(log n)
recurrance relation - T(n) = t(n/2)+1
*/
#include<iostream>
using namespace std;

int fastExponentiation(int a, int n)
{
    if (a == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return a;
    }
    else
    {
        int r = fastExponentiation(a,n/2);
        cout << r<< endl;
        if (n%2 == 0)
        {
            return r*r;
        }
        else
        {
            return r*r*a;
        }
        
    }
    
}

int main()
{
    cout <<  fastExponentiation(2,50);
    return 0;
}