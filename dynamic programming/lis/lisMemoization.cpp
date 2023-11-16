#include<iostream>
using namespace std;
#include <vector>

int calLis(int arr[], int n , int index, int prev , vector<vector<int>> &dp)
{
    if(index == n)
    {
        return 0;
    }

    if (dp[index][prev+1] != -1)
    {
        return dp[index][prev+1];
    }
    
    int length = 0 + calLis(arr,n,index+1, prev, dp);

    if (prev == -1 || arr[index] > arr[prev])
    {
        length = max(length, 1+ calLis(arr,n,index+1, index, dp));
    }

    return dp[index][prev+1] = length;
    
    
}

int lis(int arr[], int n )
{
    vector<vector<int> > dp(n+1,vector<int>(n+1,-1));

    return calLis(arr,n,0,-1,dp);
}   

int main()
{
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(arr)/sizeof(int);

    cout << lis(arr,n);

    return 0;
}