#include <iostream>
#include <conio.h>
using namespace std;
void printBoard(char[][3]);
void registerMove(char[][3], char, string);
bool isOutOfBounds(string move);
bool isFreeSpace(char[][3], string move);
void switchPlayer(char &player);
bool checkRows(char[][3], char);
bool checkColumns(char[][3], char);
bool checkDiagonals(char[][3], char);
bool isWinner(char[][3], char);
int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    char player = 'X';
    string move;
    int count = 9;
    while (count != 0)
    {
        printBoard(board);
        cout << "It's player " << player << "'s turn." << endl;
        cout << "Enter your move (e.g A1,B3 etc): ";
        cin >> move;
        if (isOutOfBounds(move))
        {
            cout << "Invalid move\nPress any key to try again...................";
            getch();
            continue;
        }
        if (isFreeSpace(board, move))
        {
            registerMove(board, player, move);
        }
        else
        {
            cout << "The box is already taken\nPress any key to try again...............";
            getch();
            continue;
        }
        if (isWinner(board, player))
        {
            printBoard(board);
            cout << "Player " << player << " has won the game";
            break;
        }
        switchPlayer(player);
        count--;
    }
    if (count == 0)
    {
        printBoard(board);
        cout << "It's a tie.";
    }
}

void printBoard(char board[][3])
{
    system("cls");
    cout << "   1   2   3" << endl;
    cout << "A  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "B  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "  ---+---+---" << endl;
    cout << "C  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool isOutOfBounds(string move)
{
    int row = move[0] - 'A';
    int column = move[1] - '1';
    if (row < 0 || row > 2 || column < 0 || column > 2)
    {
        return true;
    }
    else
    {
        return false;
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

void switchPlayer(char &player)
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
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