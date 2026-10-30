#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();

    // Check column
    for (int r = 0; r < n; r++) {
        if (board[r][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
        if (board[r][c] == 1) {
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<vector<int>>& board, int row,
                 int fixedRow, int fixedCol, int& solutions) {
    int n = board.size();

    if (row == n) {
        solutions++;

        cout << "\nSolution " << solutions << ":\n";
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << (board[r][c] ? "Q " : ". ");
            }
            cout << endl;
        }
        return;
    }

    // Keep the user-placed queen fixed and move to the next row
    if (row == fixedRow) {
        solveNQueens(board, row + 1, fixedRow, fixedCol, solutions);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, fixedRow, fixedCol, solutions);
            board[row][col] = 0;  // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter size of chessboard: ";
    cin >> n;

    if (n <= 0) {
        cout << "Board size must be positive.\n";
        return 0;
    }

    int row, col;
    cout << "Enter the first queen's row (1-" << n << "): ";
    cin >> row;
    cout << "Enter the first queen's column (1-" << n << "): ";
    cin >> col;

    if (row < 1 || row > n || col < 1 || col > n) {
        cout << "Invalid queen position.\n";
        return 0;
    }

    int fixedRow = row - 1;
    int fixedCol = col - 1;

    vector<vector<int>> board(n, vector<int>(n, 0));
    board[fixedRow][fixedCol] = 1;

    int solutions = 0;
    solveNQueens(board, 0, fixedRow, fixedCol, solutions);

    if (solutions == 0) {
        cout << "No solution exists for that fixed queen position.\n";
    } else {
        cout << "\nTotal solutions: " << solutions << endl;
    }

    return 0;
}