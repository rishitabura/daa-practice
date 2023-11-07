#include <iostream>
#include <algorithm>
using namespace std;
#define V 4
#define INFINITE 9999

void shortestpath(int G[V][V])
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
        
    }

    for (int i = 0; i < V; i++)
    {
        for ( int j = 0; j < V; j++)
        {
            if (G[i][j] == INFINITE)
            {
                cout << "Infi" << "\t";
            }
            else
            {
                cout << G[i][j] << "\t";
            }
            
        }
        cout << endl;
        
    }
    
    
}

int main()
{
    int G[V][V] = { {0, 3, INFINITE, 7},
                    {8, 0, 2, INFINITE},
                    {5, INFINITE, 0, 1},
                    {2, INFINITE, INFINITE, 0}
                };

    //  int G[V][V] = { { 0, 5, INFINITE, 10 },
    //                     { INFINITE, 0, 3, INFINITE },
    //                     { INFINITE, INFINITE, 0, 1 },
    //                     { INFINITE, INFINITE, INFINITE, 0 } };
    
    shortestpath(G);
    return 0;
}