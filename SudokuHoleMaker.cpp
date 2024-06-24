#include "SudokuHoleMaker.h"
#include

void SudokuHoleMaker::makeHoles(SudokuBoard& word) {
for (int i = 0; i < 9; i++) {
for (int j = 0; j < 9; j++) {
int a = rand() % 10;
if (a < 2)
word.board[i][j] = 32; // 使用32來表示空格
}
}
}
