#include <iostream>
using namespace std;
void printBoard(char[][3]);
void registerMove(char[][3], char, string);
bool isFreeSpace(char[][3], string move);
bool checkRows(char[][3], char);
bool checkColumns(char[][3], char);
bool checkDiagonals(char[][3], char);
bool isWinner(char, char[][3]);
int main()
{
}

void printBoard(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

bool isFreeSpace(char board[][3], string move)
{
    int row = move[0] - 'A';
    int column = move[1] - '1';
    if (board[row][column] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void registerMove(char board[][3], char player, string move)
{
    int row = move[0] - 'A';
    int column = move[1] - '1';
    board[row][column] = player;
}

bool checkRows(char board[][3], char player)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        count = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == player)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
    }
    return false;
}

bool checkColumns(char board[][3], char player)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        count = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == player)
            {
                count++;
            }
        }
        if (count == 3)
        {
            return true;
        }
    }
    return false;
}

bool checkDiagonals(char board[][3], char player)
{
    int count = 0;
    // Check left diagonal
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] == player)
        {
            count++;
        }
    }
    if (count == 3)
    {
        return true;
    }
    // Check right diagonal
    count = 0;
    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
    {
        if (board[i][j] == player)
        {
            count++;
        }
    }
    if (count == 3)
    {
        return true;
    }
    return false;
}

bool isWinner(char board[][3], char player)
{
    return checkRows(board, player) || checkColumns(board, player) || checkDiagonals(board, player);
}