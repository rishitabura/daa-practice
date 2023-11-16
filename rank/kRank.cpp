#include<bits/stdc++.h>
using namespace std;

int n = 12;
double g(int A[])
{
    if (n%2!=0)
    {
        return (double)A[n/2];
    }
    return (double)(a[(n-1)/2] + a[n/2] )/2;
}
int rank(int A[], int target, int n) {
    int sortedArr = arr; // Create a copy of the original array
    sort(sortedArr, sortedArr+n); // Sort the array

    auto it = std::find(sortedArr.begin(), sortedArr.end(), target);

    if (it != sortedArr.end()) {
        int rank = std::distance(sortedArr.begin(), it) + 1;
        return rank;
    } else {
        // Element not found in the array
        return -1;
    }
}

void f(int A[],int k)
{
    sort(A,A+n);
    int a = g(A);
    int r = rank(a);

}
int main()
{
    
    return 0;
}