/*
goal : find the min and max element in an array
using divide and conquer
time - O(n)
T(n) = 2T(n/2) + 2
no of comparision - 3n/2-2
space - O(1)
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void minMaxDnC(int a[], int l, int h, int &min, int &max)
{
    // int max, min;
    if (l == h)
    {
        max = a[l];
        min = a[l];
    }
    // if two elements
    else if (l + 1 == h)
    {
        if (a[l] < a[h])
        {
            min = a[l];
            max = a[h];
        }
        else
        {
            min = a[h];
            max = a[l];
        }
    }
    else
    {
        int mid = (l + h) / 2;
        int leftMin, leftMax, rightMin, rightMax;

        minMaxDnC(a, l, mid, leftMin, leftMax);
        minMaxDnC(a, mid + 1, h, rightMin, rightMax);

        max = (leftMax > rightMax) ? leftMax : rightMax;
        min = (leftMin < rightMin) ? leftMin : rightMin;
    }

    
}
int main()
{
    int arr[] = {45, 64, 23, 12, 67, 88};
    int n = sizeof(arr) / sizeof(int);
    int min,max;
    minMaxDnC(arr, 0, n - 1, min, max);

    cout << "Min : " << min << endl;
    cout << "Max : " << max;

    return 0;
}