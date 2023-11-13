/*
goal : to find find all possible subsets such that its sum is equal to the target
time - O(2^n)
*/

#include <iostream>
#include <vector>
using namespace std;

bool flag = false;

void sumsubsets(int w[], int i, int n, int m, vector<int> &subset)
{

    if (m == 0)
    {
        flag = true;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << "]";
        return;
    }

    if (i == n)
    {
        return;
    }

    sumsubsets(w,i+1,n,m,subset);

    if (w[i] <= m)
    {
        subset.push_back(w[i]);

        sumsubsets(w, i + 1, n, m - w[i], subset);

        subset.pop_back();
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