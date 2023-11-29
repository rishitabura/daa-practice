#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void exactlyone(int a[], int l, int h)
{
    if (l > h)
    {
        return;
    }
    if (l == h)
    {
        cout << a[l];
        return;
    }
    int mid = (l + h) / 2;
    if (mid % 2 == 0)
    {
        if (a[mid] == a[mid + 1])
        {
            exactlyone(a, mid + 2, h);
        }
        else
        {
            exactlyone(a, l, mid);
        }
    }
    if (mid % 2 != 0)
    {
        if (a[mid] == a[mid - 1])
        {
            exactlyone(a, mid + 1, h);
        }
        else
        {
            exactlyone(a, l, mid - 1);
        }
    }
}

int main()
{
    int a[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    exactlyone(a,0, n-1);
    return 0;
}