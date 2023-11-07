#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findGCD(int nums[],int n)
{
    sort(nums,nums+n);
    int a = nums[0];
    int b = nums[n - 1];

    if (a % b == 0)
    {
        return a;
    }
    else
    {
        for (int i = b; i >= 2; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                cout << b<< endl;
                return i;

            }
        }
    }

    return 1;
}
int main()
{
    int a[] = {7,5,6,8,3};
    int n = sizeof(a)/sizeof(a[0]);
    cout << findGCD(a,n);
    return 0;
}