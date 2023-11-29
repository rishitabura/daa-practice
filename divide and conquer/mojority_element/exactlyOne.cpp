
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int exactlyOne(int a[], int n)
{
    int element = -1;

    for (int i = 0; i < n; i+=2)
    {
       if(a[i] != a[i+1])
       {
        element = a[i];
        break;
       }
    }
    if(a[n-1]!= a[n-2])
    {
        element = a[n-1];
    }
    
    return element;
}

int main()
{
    int a[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int n = sizeof(a) / sizeof(a[0]);
    cout  << exactlyOne(a, n);
    return 0;
}
