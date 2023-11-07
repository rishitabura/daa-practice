#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i]  < lis[j]+1)
            {
                lis[i] = lis[j]+1;
            }
        }
    }

    return *max_element(lis,lis+n);
    
}
int main()
{
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(arr)/sizeof(int);

    cout << lis(arr,n);
    return 0;
}