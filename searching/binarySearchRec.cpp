/*
goal : to search an element in sorted array
time - O(logn)
space - O(1)
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int binarySearch(int arr[], int l , int h , int key)
{
    if (h == 1)
    {   
        if (arr[l] ==  key)
        {
            return l;
        }
        else
        {
            return -1;
        }
        
    }
    
    while (l<=h)
    {
        int mid = (l+h)/2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch(arr,l,mid-1, key);
        }
        else
        {
            return binarySearch(arr,mid+1, h, key);
        }
        
    }
    return -1;
    
}
int main()
{
    int arr[] = {4,32,54,67,75,89};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << binarySearch(arr,0,n,54);
    return 0;
}