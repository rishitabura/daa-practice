/*
goal : find the no of incversion i<j and a[i] > a[j]
min count - 0 (when already  sorted)
max count  (when in reverse order - descending order)
time = O(nlogn)
space = O(n)
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cnt = 0;

void merge(int a[], int l, int h, int mid)
{
    int n = 8;
    int i = l;
    int j = mid + 1;
    int k = 0;
    int b[n];

    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        { // right is less than left
            b[k] = a[j];
            cnt += mid - i + 1;
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int z = l; z <= h; z++)
    {
        a[z] = b[z - l];
    }
}
void mergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, h, mid);
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    // int arr[] = {9,3,7,5,6,4,8,2};
    int arr[] = {43,39,34,20,6,5,4,1};

    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << cnt << endl;
    print(arr, n);

    return 0;
}