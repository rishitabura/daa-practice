/*
goal : to sort the array using insertion sort
time - O(n^2)
space - O(1)
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];   
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}