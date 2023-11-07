#include<iostream>
using namespace std;

int modulo(int a, int n, int m)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n%2 == 0)
        {
            return ((modulo(a,n/2,m)%m)*(modulo(a,n/2,m)%m))%m;
        }
        else
        {
            return ((modulo(a,n/2,m)%m)*(modulo(a,n/2,m)%m)*a)%m;
        }
        
    }
    
}
int main()
{
    cout << modulo(3,41,7);
    return 0;
}