#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

char board[ROWS][COLS];

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = '.';
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < COLS; i++)
        cout << " " << i;
    cout << "\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << " " << board[i][j];
        }
        cout << "\n";
    }
}

// Function to drop the disc in the chosen column
bool dropDisc(int col, char disc) {
    if (col < 0 || col >= COLS || board[0][col] != '.') {
        return false; // Invalid move
    }

    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == '.') {
            board[i][col] = disc;
            return true;
        }
    }
    return false; // Column full
}

// Check 4 in a row (horizontal, vertical, diagonal)
bool checkWin(char disc) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j <= COLS - 4; j++)
            if (board[i][j] == disc && board[i][j + 1] == disc &&
                board[i][j + 2] == disc && board[i][j + 3] == disc)
                return true;

    // Check vertical
    for (int i = 0; i <= ROWS - 4; i++)
        for (int j = 0; j < COLS; j++)
            if (board[i][j] == disc && board[i + 1][j] == disc &&
                board[i + 2][j] == disc && board[i + 3][j] == disc)
                return true;

    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++)
        for (int j = 0; j <= COLS - 4; j++)
            if (board[i][j] == disc && board[i - 1][j + 1] == disc &&
                board[i - 2][j + 2] == disc && board[i - 3][j + 3] == disc)
                return true;

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; i++)
        for (int j = 0; j <= COLS - 4; j++)
            if (board[i][j] == disc && board[i + 1][j + 1] == disc &&
                board[i + 2][j + 2] == disc && board[i + 3][j + 3] == disc)
                return true;

    return false;
}

// Main function
int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int moves = 0;
    const int MAX_MOVES = ROWS * COLS;

    while (true) {
        displayBoard();
        int col;
        cout << "Player " << currentPlayer << ", enter column (0-6): ";
        cin >> col;

        if (!dropDisc(col, currentPlayer)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        moves++;
        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (moves == MAX_MOVES) {
            displayBoard();
            cout << "Game is a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
