/*
time - O(n^2)
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Job
{
    char id;
    int profit;
    int dead;
};

bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}

void scheduling(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << arr[result[i]].id << " ";
        }
    }
}

int main()
{
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";

    // Function call
    scheduling(arr, n);
    return 0;
}