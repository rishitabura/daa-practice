#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sorting(int a[], int n)
{
    sort(a, a+n);
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i])
        {
            count++;
        }
        else
        {
            if (count > n / 2)
            {
                return a[i - 1];
            }
            else
            {
                count = 1;
            }
        }
    }
    if (count > n / 2)
    {
        return a[n - 1];
    }
    return -1;
}

int main()
{
    int a[] = {2, 4, 5, 2, 2, 6, 7, 2, 2};
    cout << "Majority element : " << sorting(a, 9);
    return 0;
}
