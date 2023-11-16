/* 
Time - O(n^2)
Space - O(n)    due to array creation
*/
#include<iostream>
using namespace std;

int josephus(int n, int k)
{
    int index = 0;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        // cout << arr[i] << " ";
    }

    // cout << endl;

    while (n>1)
    {
        index = (index+k-1)%n;
        cout << index << " " << arr[index] << endl;
        for (int i = index; i < n-1; i++)
        {
            arr[i] = arr[i+1];
        }
        n--;
    }
    
    return arr[0];
}

int main()
{
    cout << "Remain:" << josephus(5,3);
    return 0;
}