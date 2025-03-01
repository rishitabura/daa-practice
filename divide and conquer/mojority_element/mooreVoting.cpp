/*
goal : find the element appreaing more then n/2 times in an array
using moore's voting algo
time - O(n)
*/

#include <iostream>
using namespace std;

int mooreVoting(int a[], int n)
{
    int count =0;
    int element = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = a[i];
        }
        else if (a[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
        
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == element)
        {
            count1++;
        }
    }
    // if (count1>n/2)
    // {
    //     return element;
    // }

    // return -1;
    return (count1>n/2)? element : -1;
    
}

int main()
{
    int a[] = {2,4,5,2,2,6,7,2,2};
    cout << "Majority element : " << mooreVoting(a,9);
    return 0;
}
