#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key)
{
    int flag = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] ==  key) 
        {
            flag = 1;
            ans = i;
        }
    }

    if (flag)
    {
        cout << "Found at index " << ans;
    }
    else
    {
        cout << "Not found";
    }
    

}

int main()
{
    int arr[] = {44, 23, 13, 64, 65, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    linearSearch(arr,n,43);
    return 0;
}