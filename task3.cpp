#include <bits/stdc++.h>
using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "Current Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----" << endl;
    }
}

bool placeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = player;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void switchPlayer(char& currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';

        while (true) {
            displayBoard(board);
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (placeMove(board, row, col, currentPlayer)) {
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }
                if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                    break;
                }
                switchPlayer(currentPlayer);
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;
}


