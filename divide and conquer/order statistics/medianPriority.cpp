#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

double median(int arr1[], int arr2[], int m, int n, priority_queue<int, vector<int>, greater<int>> &pq)
{
    for (int i = 0; i < m; i++)
    {
        pq.push(arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        pq.push(arr2[i]);
    }

    int t = m+n;
    double mid1, mid2;
    int count = -1;
    while (!pq.empty())
    {
        count ++;

        if (t %2 != 0 && count == t/2)
        {
            double ans = pq.top();
            return ans;
        }

        if (t%2 == 0 && count == t/2)
        {
            mid1 = pq.top();
        }
        if (t%2== 0 && count == (t/2)-1)
        {
            mid2 = pq.top();
            double ans = (mid1+mid2)/2;
            return ans;
        }
        pq.pop();
        
    }
    return -1;
    
}
int main()
{
    int arr1[] = {1,2};
    int arr2[] = {3,4,6};
    int m = sizeof(arr1)/sizeof(int);
    int n = sizeof(arr2)/sizeof(int);

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << median(arr1, arr2, m,n,pq);
    return 0;
}