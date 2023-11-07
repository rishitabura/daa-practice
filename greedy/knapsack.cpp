#include<iostream>
using namespace std;

void knapsack(int obj[], float p[], float w[], int n)
{
    float ans;

    float fract[n];
    for (int i = 0; i < n; i++)
    {
        fract[i] = p[i]/w[i];
        cout << fract[i] << " ";
    }


    int x[n];
    
    
    // return ans;
}
int main()
{
    int obj[] = {1,2,3,4,5,6,7};
    int n = sizeof(obj)/sizeof(int);
    float p[] = {10,5,15,7,6,18,3};
    float w[] = {2,3,5,7,1,4,1};

    knapsack(obj,p,w,n);


    return 0;
}