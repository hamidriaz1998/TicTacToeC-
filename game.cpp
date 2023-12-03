#include <iostream>
using namespace std;
bool isWinner(char, char[][3]);
bool checkRows(char[][3], char);
bool checkColumns(char[][3], char);
bool checkDiagonal(char[][3], char);
void printBoard(char[][3]);
void registerMove(char[][3], char, string);
bool isFreeSpace(char[][3], string move);
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