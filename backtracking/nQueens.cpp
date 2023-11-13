#include <iostream>
using namespace std;
#define N 4

bool check(int board[N][N], int row, int col)
{
    // row check
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    // upper diagonal check on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // for lower digonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solve(int board[N][N], int col)
{
    if (col >= N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (check(board, i, col))
        {
            board[i][col] = 1;

            if (solve(board, col + 1))
            {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void prinSol(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
            {
                cout << "Q" << i + 1 << "\t";
            }
            else
            {
                cout << ".\t";
            }
        }

        cout << endl;
    }
}
int main()
{
    int board[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = 0;
        }
    }
    // for(int i = 0; i<N ; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;

    // }

    if (solve(board, 0) == false)
    {
        cout << "Solution does not exist";
    }
    prinSol(board);

    return 0;
}