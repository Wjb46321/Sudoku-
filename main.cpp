#include
#include
#include
#include "SudokuBoard.h"
#include "SudokuFiller.h"
#include "SudokuHoleMaker.h"
#include "SudokuChecker.h"

using namespace std;

int main() {
srand(time(0));

SudokuBoard board;
SudokuFiller filler;
SudokuHoleMaker holeMaker;
SudokuChecker checker;

// 填充數獨盤面
filler.fillBoard(board);

// 保存答案盤面
SudokuBoard solution = board;

// 挖空格子
holeMaker.makeHoles(board);

cout << "數獨遊戲" << endl << endl;
board.printBoard();

// 玩家輸入數字
cout << endl << "請輸入答案" << endl << endl;
for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        int a;
        if (board.board[i][j] == 32) {
            do {
                cout << "第" << i + 1 << "行 第" << j + 1 << "列: ";
                cin >> a;
            } while (a > 9 || a < 1);
            board.board[i][j] = a;
            cout << endl;
        }
    }
}

// 輸出玩家輸入後的盤面
cout << "你的答案:" << endl;
board.printBoard();

// 判斷是否符合數獨
bool isCorrect = checker.checkSudoku(board);

if (isCorrect)
    cout << "恭喜你！你贏了！！" << endl;
else {
    cout << "你輸了..." << endl << "正確答案:" << endl;
    solution.printBoard();
}

return 0;
}

