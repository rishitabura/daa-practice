/* 
Time - O(n)
Space - O(n)    due to recursion stack is  used 
*/

#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    if (n==1)
    {
        return 1;
    }
    // return (josephus(n-1,k)+k)%n;
    return (josephus(n-1,k)+k-1)%n+1;

    
}

int main(int argc, char const *argv[])
{
    cout << josephus(7,3);   
    return 0;
}
