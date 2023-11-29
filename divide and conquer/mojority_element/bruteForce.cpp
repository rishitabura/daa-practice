/*
goal : find the element appreaing more then n/2 times in an array
using brute force
time - O(n^2)
*/
#include <iostream>
using namespace std;

int majorityBrute(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
            
        }
        if (count>n/2)
        {
            cout << "Count = " << count;
            return a[i];
        }
        
    }
    return -1;
    
}   
int main()
{
    int a[] = {2,4,5,2,2,6,7,2,2};
    cout << "Majority element : " << majorityBrute(a,9);
    return 0;

}