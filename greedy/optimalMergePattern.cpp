/*
goal: find the minimum computations done to reach the Optimal Merge Pattern
using priority queue
time - O(nlogn)
space - O(n)
*/
#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

int  optimalMerge(int arr[], int n)
{
    sort(arr,arr+n);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int count = 0;
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int weight = first+ second;

        count += weight;

        pq.push(weight);
    }


    return count;
    
}
int main()
{
    int arr[] = { 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << optimalMerge(arr,n);
    
    return 0;
}