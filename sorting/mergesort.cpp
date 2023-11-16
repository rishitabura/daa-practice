/*
goal : to sort the array using mergesort
using divide and conquer
time - O(nlogn)
space - O(n)
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int c = 0;

void merge(int A[], int l, int h, int mid, int n)
{
    int i = l;
    int j = mid + 1;
    int B[n];
    int k = l;

    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
            c++;
        }
        if (A[i] > A[j])
        {
            B[k] = A[j];
            j++;
            k++;
            c++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int z = l; z <= h; z++)
    {
        A[z] = B[z];
    }
}

void mergeS(int A[], int l, int h, int n)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeS(A, l, mid, n);
        mergeS(A, mid + 1, h, n);
        merge(A, l, h, mid, n);
    }
}

int main()
{
    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeS(arr, 0, n - 1,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nTotal number of swaps : " << c;

    return 0;
}