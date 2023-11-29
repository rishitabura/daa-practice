/*
insertion sort algorithm
time - O(n^2)
space - O(n)
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

int main()
{
    int arr[] = {10, 16, 8, 12, 15, 6, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}