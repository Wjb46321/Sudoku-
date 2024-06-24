#include "SudokuFiller.h"

void SudokuFiller::fillBoard(SudokuBoard& word) {
int countRow[9][10] = { 0 }, countCol[9][10] = { 0 }, countGe[9][10] = { 0 };
int x;

// 填充第4格
for (int i = 3; i <= 5; i++) {
    for (int j = 3; j <= 5; j++) {
        do {
            x = rand() % 9 + 1;
        } while (countGe[4][x]);
        word.board[i][j] = x;
        countRow[i][x] = countCol[j][x] = countGe[4][x] = 1;
    }
}

// 填充其餘格子
fillOtherGrids(word, countRow, countCol, countGe);
}

void SudokuFiller::fillOtherGrids(SudokuBoard& word, int countRow[9][10], int countCol[9][10], int countGe[9][10]) {
int x;
// 填充第3格
for (int i = 3; i <= 5; i++) {
for (int j = 0; j <= 2; j++) {
word.board[i][j] = word.board[(i - 1 + 3) % 3 + 3][j + 3];
x = word.board[i][j];
countRow[i][x] = countCol[j][x] = countGe[3][x] = 1;
}
}

// 填充第5格
for (int i = 3; i <= 5; i++) {
    for (int j = 6; j <= 8; j++) {
        word.board[i][j] = word.board[(i + 1 + 3) % 3 + 3][j - 3];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[5][x] = 1;
    }
}

// 填充第1格
for (int i = 0; i <= 2; i++) {
    for (int j = 3; j <= 5; j++) {
        word.board[i][j] = word.board[i + 3][(j - 1 + 3) % 3 + 3];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[1][x] = 1;
    }
}

// 填充第7格
for (int i = 6; i <= 8; i++) {
    for (int j = 3; j <= 5; j++) {
        word.board[i][j] = word.board[i - 3][(j + 1 + 3) % 3 + 3];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[7][x] = 1;
    }
}

// 填充第0格
for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
        word.board[i][j] = word.board[i + 3][(j - 1 + 3) % 3];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[0][x] = 1;
    }
}

// 填充第6格
for (int i = 6; i <= 8; i++) {
    for (int j = 0; j <= 2; j++) {
        word.board[i][j] = word.board[i - 3][(j + 1 + 3) % 3];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[6][x] = 1;
    }
}

// 填充第2格
for (int i = 0; i <= 2; i++) {
    for (int j = 6; j <= 8; j++) {
        word.board[i][j] = word.board[i + 3][(j - 1 + 3) % 3 + 6];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[2][x] = 1;
    }
}

// 填充第8格
for (int i = 6; i <= 8; i++) {
    for (int j = 6; j <= 8; j++) {
        word.board[i][j] = word.board[i - 3][(j + 1 + 3) % 3 + 6];
        x = word.board[i][j];
        countRow[i][x] = countCol[j][x] = countGe[8][x] = 1;
    }
}
}
