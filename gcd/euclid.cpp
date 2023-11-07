#include<iostream>
using namespace std;

int gcdEuclids(int m, int n)
{
    if (n%m == 0)
    {
        return m;
    }
    while (m>0)
    {
        int r = n%m;
        return gcdEuclids(r,m);
    }

}
int main()
{
    cout << gcdEuclids(30,2);
    return 0;
}