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
        return 0;
    }
    return (josephus(n-1,k)+k)%n;
    
}

int main(int argc, char const *argv[])
{
    cout << josephus(5,2);   
    return 0;
}
