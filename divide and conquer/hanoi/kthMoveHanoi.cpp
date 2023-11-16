/*
goal : find moves of tower of hanoi
using divide and conquer (recursion)
time = O(2^n)
space = O(n)
recurrance relation - T(n) = 2T(n-1) + 1;
no of moves - 2^n-1
*/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void hanoi(char sour, char dest, char inter, int n, double k)
{
    if (n== 0)
    {
        cout << "No disk present";
        return;
    }
    
    if (n==1)
    {
        cout<< "Move disk "<< n << " from " << sour << " to " << dest << endl;
    }
    else if (n == 2)
    {
        if (k == 1)
        {
            cout<< "Move disk "<< n-1 << " from " << sour << " to " << inter << endl;
        }
        if (k == 2)
        {
            cout<< "Move disk "<< n << " from " << sour << " to " << dest << endl;
        }
        if (k == 3)
        {
            cout<< "Move disk "<< n-1 << " from " << inter << " to " << dest << endl;
        }
        
    }
    else
    {
        // 2^(n-1) - 1 is used to calculate the number of moves for n−1 disks
        double rem = pow(2,n-1) - 1;
        if (k <= rem)
        {
            hanoi(sour,inter, dest, n-1, k);
        }
        if (k == rem+1)
        {
            cout << "Move disk "<< n << " from " << sour << " to " << dest << endl;
        }
        else
        {
            hanoi(inter, dest, sour, n-1, (k - rem -1));
        }
    }
    
}
int main()
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    int n = 3;

    hanoi(A,C,B,n,5);
    
    
    return 0;
}