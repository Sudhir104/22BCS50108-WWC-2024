#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char> > board;
    char currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char> >(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void printBoard() {
        cout << "Current board:\n";
        for (int i = 0; i < 3; i++) {
            cout << "  " << i + 1 << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " |\n";
            if (i < 2) {
                cout << "    -----------\n";
            }
        }
        cout << "    1   2   3\n";
    }

    bool isWinner() {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool isBoardFull() {
    for (vector<vector<char> >::const_iterator row = board.begin(); row != board.end(); ++row) {
        for (vector<char>::const_iterator cell = row->begin(); cell != row->end(); ++cell) {
            if (*cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        while (true) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            row--;
            col--;

            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (isWinner()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}