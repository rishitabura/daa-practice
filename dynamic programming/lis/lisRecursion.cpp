/*
longest increasing subsequence problem
Using recursion
time - O(2^n)
space - O(n)
*/

#include<iostream>
using namespace std;

int lis(int arr[], int n, int index, int prev)
{
    if (index == n)
    {
        return 0;
    }

    int length = 0 + lis(arr,n,index+1, prev);

    if (prev == -1 || arr[index] > arr[prev])
    {
        length = max(length, 1 + lis(arr,n,index+1, index));
    }

    return length;

}
int main()
{
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(arr)/sizeof(int);
    cout << lis(arr,n ,0, -1);
    return 0;
}