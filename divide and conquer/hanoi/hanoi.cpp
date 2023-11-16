/*
Time = O(2^n)
Space = O(n)
Recurrance relation - T(n) = 2^n-1
*/

#include<iostream>
using namespace std;

int count = 0;
void hanoi(char sour, char dest, char inter, int n)
{
    if (n==1)
    {
        cout<< "Move disk "<< n << " from " << sour << " to " << dest << endl;
        count++;
    }
    else
    {
        hanoi(sour,inter, dest,n-1);
        cout<< "Move disk "<< n << " from " << sour << " to " << dest << endl;
        count++;
        hanoi(inter,dest,sour,n-1);

    }
   
    
}
int main()
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    int n = 3;

    hanoi(A,C,B,n);
     cout << "Total number of moves : "<< count;
    
    
    return 0;
}