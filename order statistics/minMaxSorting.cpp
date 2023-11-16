#include<bits/stdc++.h>
/*
goal : find the min and max element in an array
using sorting
time - O(nlogn)
space - O(1)
*/
#include<iostream>
using namespace std;

void minMax(int a[], int n)
{
    sort(a,a+n);
    int min = a[0];
    int max = a[n-1];

    cout << "Min : " << min << " & Max : " << max;


}
int main()
{
    int a[] = {45,64,23,12,67,88};
    int n = sizeof(a)/sizeof(a[0]);
    minMax(a,n);
    return 0;
}