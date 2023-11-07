/* 
Median of Two Sorted Arrays -
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Time = O(nlogn)
space = O(n)
*/

#include <iostream>
using namespace std;


float merge(int a[], int b[], int m ,int n)
{
    int i = 0;
    int l = i;
    int j = 0;
    int k = 0;
    int c[m+n];

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {   
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }

    for (int z = 0; z < m+n; z++)
    {
        cout << c[z] << " ";
    }
    int t = m+n;
    float median;
    if (t%2 !=0)
    {
        int mid = (0+t)/2;
        median = (float)c[mid];
        
    }
    else
    {
        int mid = (0+t)/2;
        int mid1 = mid-1;
        median = (float)(c[mid] + c[mid1])/2;

    }

      return median;
    
   
}


int main()
{
    int arr1[] = {1,2};
    int arr2[] = {3,4,6};
    int m = sizeof(arr1)/sizeof(int);
    int n = sizeof(arr2)/sizeof(int);
    cout << endl << "Median : "<< merge(arr1,arr2,m,n);
    return 0;
   
}