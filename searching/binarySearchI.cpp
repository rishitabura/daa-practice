/*
goal : to search an element in sorted array
time - O(logn)
space - O(1)
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n ,int key)
{
    // sort(arr,arr+n);
    int mid;
    int l = 0;
    int h = n;
    while (l<=h)
    {
        mid = (l+h)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            h = mid -1;
        }
        else
        {
            l = mid+1;
        }
    }

    return -1;
    // return l;   // for search insert 
    
}
int main()
{
    int arr[] = {5,35,37,43,68,87};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << binarySearch(arr,n, 43);
    return 0;
}