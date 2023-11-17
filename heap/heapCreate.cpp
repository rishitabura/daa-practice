/*
goal : create a heap
using heapify
time - O(n)
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// take log n
void heapify(int arr[], int n , int i)
{
    int largest = i;

    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }


    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr,n,largest);
    }
    
}

// O(n)
void buildheap(int a[], int n)
{
    int lastNonLeafnode = (n/2) - 1;

    for (int i = lastNonLeafnode; i >= 0; i--)
    {
        heapify(a,n,i);
    }
    
}
int main()
{
    int arr[] = {1, 3, 14, 6, 3, 10, 9, 8, 12, 7};
    int n = sizeof(arr)/sizeof(int);

    buildheap(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}