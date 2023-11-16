/*
goal : find the element appreaing more then n/2 times in an array
using divide and conquer
time - O(nlogn)
*/

#include <iostream>
using namespace std;

int majority(int a[], int l, int h)
{
    if (l == h)
    {
        return a[l];
    }

    int mid = (l + h) / 2;
    int left = majority(a, l, mid);
    cout << "Left " << left << endl;
    int right = majority(a, mid + 1, h);
    cout << "Right " << right << endl;

    if (left == right)
    {
        return left;
    }
    int leftcount = 0;
    int rightcount = 0;

    for (int i = l; i <=h; i++)
    {
        if (a[i] == left)
        {
            leftcount++;
        }
        else
        {
            rightcount++;
        }
        
    }
    
    if (leftcount > (h - l + 1)/ 2)
    {
        return left;
    }
    else if (rightcount > (h - l + 1)/ 2)
    {
        return right;
    }
    else
    {
        return -1;
    }
    // return leftcount>rightcount ? left : right;
}

int main(int argc, char const *argv[])
{
    // int a[] = {2, 4, 5, 2, 2, 6, 7, 2, 2};
    int a[] = {3,3,4,2,4,4,2,4,4};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Majority element : " << majority(a, 0, n - 1);
    return 0;
}
