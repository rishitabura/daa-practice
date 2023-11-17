/*
goal: sort the array using heapify
time - o(nlogn)
space - O(logn)
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void heapify(int arr[], int n , int i) 
{
    int largest = i;

    int left = 2*i+1;
    int right = 2*i+2;

    if (left<n && arr[left] >arr[i] )
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[i])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);

        heapify(arr,n,largest);
    }
    
}

void heapSort(int arr[], int n)
{
    int lastNonLeafNode = (n/2)-1;
    for (int i = lastNonLeafNode; i >= 0; i--)
    {
        heapify(arr,n,i);
    }

    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }

    
    
}
int main()
{
    int arr[] = {1, 3, 14, 6, 3, 10, 9, 8, 12, 7};
    int n = sizeof(arr)/sizeof(int);

    heapSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}