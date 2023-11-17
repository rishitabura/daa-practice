#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int kthsmallest(int arr[], int n , int k ,  priority_queue<int> &pq)
{
     for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{
    int arr[] = {10,20,60,30,50,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    // sort(arr,arr+n);

    //  for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    priority_queue<int> pq;
    cout << kthsmallest(arr,n, k, pq);

    return 0;
}