#include <stdbool.h>
#include <stdio.h>
#define N 8
void Solution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool Check(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool Solve(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {

        if (Check(board, i, col)) {
            board[i][col] = 1;

            if (Solve(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{

    int board[N][N] = { 0 };

    if (Solve(board, 0) == true) {
        Solution(board);
    }
}
