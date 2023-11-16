/*
goal : find the no of incversion i<j and a[i] > a[j]
min count - 0 (when already  sorted)
max count  (when in reverse order - descending order)
time = O(n^2)
space = O(1)
*/

#include<iostream>
using namespace std;

int inversion(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (i<j && a[i]>a[j])
            {
                count++;
            }

        }
        
    }
    return count;
    
}

int main()
{
    int a[] = {1, 20, 6, 4, 5};
    cout << inversion(a,5);
    return 0;
}