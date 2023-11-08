#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int lcs(char s1[], char s2[], int i,int j)
{
    if (s1[i] == '\0' || s2[j] == '\0')
    {
        return 0;
    }
    if (s1[i] == s2[j])
    {
        return 1+lcs(s1,s2,i+1,j+1);
    }
    else
    {
        return max(lcs(s1,s2,i+1, j), lcs(s1,s2,i,j+1));
    }
    
    
}
int main()
{
    char s1[] = {'b','d','\0'};
    char s2[] = {'a','b','c','d','\0'};

    cout << lcs(s1,s2,0, 0);
    return 0;
}