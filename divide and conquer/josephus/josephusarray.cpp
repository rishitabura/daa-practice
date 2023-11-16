/* 
Time - O(n)
Space - O(1)    
*/

#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    int i = 1;
    int ans = 0;
    while (i<=n)
    {
        ans = (ans+k)%i;
        i++;
    }
    return ans;
    
    
}

int main(int argc, char const *argv[])
{
    cout << josephus(10,6);   
    return 0;
}
