#include <iostream>
using namespace std;
#define V 5

bool isSafe(bool G[V][V], int index, int color[], int c)
{
    for (int j = 0; j < V; j++)
    {
        if (G[index][j] && c == color[j])
        {
            return false;
        }
    }

    return true;
}

bool coloring(bool G[V][V], int color[], int index, int m)
{
    if (index == V)
    {
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(G,index,color,c))
        {
            color[index] = c;

            if (coloring(G,color,index+1, m) == true)
            {
                return true;
            }

            color[index] = 0;
        }
    }

    return false;
}
int main()
{

    bool G[V][V] = {
        {0,1,0,0,1},
        {1,0,1,0,0},
        {0,1,0,1,1},
        {0,0,1,0,1},
        {1,1,1,1,0}
    };

    int m = 3;
    int color[V] = {0};

    if (coloring(G,color,0,m) ==  false)
    {
        cout << "No solution";
    }
    cout << "Solution existis\n";
    for (int i = 0; i < V; i++)
    {
        cout << color[i] << " ";
    }
    
    
    return 0;
}