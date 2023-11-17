/*
goal : find the maxi profit and wieght of objects should not exceed m
time - O(nlogn)
*/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct object
{
    int profit;
    int weight;
    object(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(struct object a,struct object b)
{
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;
    return (r1>r2);
}

double knapsack(struct object a[], int m ,int n)
{
    sort(a,a+n,cmp);

    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].weight<= m)
        {
            m -=a[i].weight;
            ans += a[i].profit;
        }

        else{
            ans += a[i].profit*((double)m/(double)a[i].weight);
            break;
        }
        
    }
    return ans;
    
}

int main()
{

    object arr[] = {{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
    // object arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
     int n = sizeof(arr)/sizeof(arr[0]);

    cout << knapsack(arr,15,n);
    return 0;
}