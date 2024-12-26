#include <iostream>
#include <unordered_set>

using namespace std;

bool isValidSudoku(char board[9][9]) {
    unordered_set<string> seen;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num != '.') {
                string row = string(1, num) + " in row " + to_string(i);
                string col = string(1, num) + " in col " + to_string(j);
                string box = string(1, num) + " in box " + to_string(i / 3) + "-" + to_string(j / 3);
                if (seen.count(row) || seen.count(col) || seen.count(box)) {
                    return false;
                }
                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }
    }

    return true;
}

int main() {
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board)) {
        cout << "The Sudoku board is valid ." << endl;
    } else {
        cout << "The Sudoku board is invalid." << endl;
    }

    return 0;
}