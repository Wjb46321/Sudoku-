#include "SudokuBoard.h"

SudokuBoard::SudokuBoard() {
// 初始化棋盤為全零
for (int i = 0; i < 9; i++)
for (int j = 0; j < 9; j++)
board[i][j] = 0;
}

void SudokuBoard::printBoard() {
for (int i = 0; i < 9; i++) {
for (int j = 0; j < 9; j++) {
if (board[i][j] == 32)
cout << " ";
else
cout << board[i][j] << " ";
}
cout << endl;
}
}
