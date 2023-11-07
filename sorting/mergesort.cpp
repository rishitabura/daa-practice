/* Time = O(nlogn)
space = O(n)
*/

#include <iostream>
using namespace std;

void merge(int a[], int l, int h, int mid)
{
    int n = 8;
    int i = l;
    int j = mid+1;
    int k = 0;
    int b[n];

    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {   
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int z = l; z <= h; z++)
    {
        a[z] = b[z-l];
    }
   
}
void mergeSort(int a[], int l, int h)
{
    int cnt=0;
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, h, mid);
    }

}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int arr[] = {9,3,7,5,6,4,8,2};
    int n = 8;
    mergeSort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}