#include<bits/stdc++.h>
#include<iostream>
#include <queue>
using namespace std;

int main()
{
    int arr[] = {57,23,8,75,12,54};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // max heap;
    priority_queue <int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    cout << "\nPriority queue (Max heap) : " ;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    

    // min heap 
    // priority_queue<int ,vector<int>,greater<int>> pq; //another way of min heap
    priority_queue <int> pqMIN;
    for (int i = 0; i < n; i++)
    {
        pqMIN.push(-arr[i]);
    }
    cout << "\nPriority queue (MIN heap) : " ;
    while (!pqMIN.empty())
    {
        cout << -pqMIN.top() << " ";
        pqMIN.pop();
    }

    
    
    return 0;
}