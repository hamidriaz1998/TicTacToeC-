#include<iostream>
using namespace std;
bool isWinner(char,char[][3]);
bool checkRows(char[][3],char);
bool checkColumns(char[][3],char);
bool checkDiagonal(char[][3],char);
void printBoard(char[][3]);
int main(){

}

void printBoard(char board[][3]){
    for (int i = 0;i<3;i++){
        for (int j=0;j<3;j++){
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
    }
}