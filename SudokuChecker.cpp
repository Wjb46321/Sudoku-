#include "SudokuChecker.h"

bool SudokuChecker::checkSudoku(SudokuBoard& word) {
int sum;
for (int i = 0; i < 9; i++) {
sum = 0;
for (int j = 0; j < 9; j++) {
sum += word.board[i][j];
}
if (sum != 45)
return false;
}

for (int i = 0; i < 9; i++) {
    sum = 0;
    for (int j = 0; j < 9; j++) {
        sum += word.board[j][i];
    }
    if (sum != 45)
        return false;
}

for (int m = 0; m < 9; m += 3) {
    for (int n = 0; n < 9; n += 3) {
        sum = 0;
        for (int i = m; i < m + 3; i++) {
            for (int j = n; j < n + 3; j++) {
                sum += word.board[i][j];
            }
        }
        if (sum != 45)
            return false;
    }
}
return true;
}
