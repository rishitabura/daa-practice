/*
goal : find the modular  
a^n = b%m    =>  a^n%m
using the formala a^n%m = [(a^n/2 % m) * (a^n/2 %m)] %m
time - O(log n)
recurrance relation - T(n) = t(n/2)+1
space - O(n)
*/
#include<iostream>
using namespace std;

int modulo(int a, int n, int m)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n%2 == 0)
        {
            return ((modulo(a,n/2,m)%m)*(modulo(a,n/2,m)%m))%m;
        }
        else
        {
            return ((modulo(a,n/2,m)%m)*(modulo(a,n/2,m)%m)*a)%m;
        }
        
    }
    
}
int main()
{
    cout << modulo(3,41,7);
    return 0;
}