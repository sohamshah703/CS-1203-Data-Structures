#include <stdio.h>
#include <stdbool.h>

#define N 8

void printSolution(int board[N][N]) {
    // Function to print the N-Queens solution board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on the board[row][col]
bool isAllowed(int board[N][N], int row, int col) {
    int i, j;

    // Check if there's a queen in the same column
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check if there's a queen on the left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check if there's a queen on the right diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// The recursive function that solves the N-Queens problem
bool solveNQueens(int board[N][N], int col) {
    if (col >= N)
        return true;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (isAllowed(board, i, col)) {
            board[i][col] = 1; // Place a queen
            if (solveNQueens(board, col + 1))
                return true;
            board[i][col] = 0; // Backtracking if no solution is found
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0}; // Initialize the N-Queens board

    if (solveNQueens(board, 0)) // Attempt to solve the N-Queens problem
        printSolution(board); // If a solution is found, print it
    else
        printf("No solution exists\n");

    return 0;
}
