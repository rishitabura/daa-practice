#include <iostream>
#include <vector>
using namespace std;

vector<int > bestSet;

bool include(int currentW, int m)
{
    return (currentW + bestSet.back() <= m );
    
}

bool exclude(int currentW, int m, int remainW)
{
    return (currentW + remainW < m);
}

void sumsubsets(int w[], int s, int n, int m, int currentW, int currentS, vector<int> &subset)
{
    if (s == n)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (include(currentW + w[i]))
        {
            subset.push_back(i);

            sumsubsets(w,s+1,n,m-w[i])
        }
        
    }
    
    
    
}
int main()
{
    int w[] = {5, 10, 12, 13, 15, 18};
    // int w[] = { 3, 34, 4, 12, 5, 2 };
    int m = 30;
    flag = false;
    int n = sizeof(w) / sizeof(int);
    vector<int> subset;
    sumsubsets(w, 0, n, m, subset);
    if (!flag)
    {
        cout << "There is no such subset";
    }

    return 0;
}