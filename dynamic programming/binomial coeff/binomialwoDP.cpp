/*
to find binomail expression 
nCr = n-1Cr-1 + n-1Cr

without using DP
time = O(2^n)
*/

#include<iostream>
using namespace std;

int binomialwoDP(int n , int r)
{
    if (r ==0 || r == n)
    {
        return 1;
    }
    return binomialwoDP(n-1,r-1) + binomialwoDP(n-1,r);

}
int main()
{
    cout << binomialwoDP(5,2);
    return 0;
}