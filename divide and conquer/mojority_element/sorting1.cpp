/*
goal : find the element appreaing more then n/2 times in an array
using sorting
time - O(nlogn)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sorting(int a[], int n)
{
    sort(a, a+n);
    return a[n/2];
}

int main()
{
    int a[] = {2, 4, 5, 2, 2, 6, 7, 2, 2};
    cout << "Majority element : " << sorting(a, 9);
    return 0;
}
