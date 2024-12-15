#include <stdio.h>
#include <limits.h>

#define SIZE 3

// Board and utility functions (as in previous example)

// Minimax function
int minimax(char board[SIZE][SIZE], int depth, int isMaximizing) {
    char result = checkWinner(board);
    
    // Terminal states
    if (result == 'X') return 1;
    if (result == 'O') return -1;
    if (isBoardFull(board)) return 0;

    if (isMaximizing) {
        int bestScore = INT_MIN;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = ' ';  // Undo the move
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = ' ';
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }
        return bestScore;
    }
}

// Find the best move for the AI (Max player)
void findBestMove(char board[SIZE][SIZE]) {
    int bestVal = INT_MIN;
    int bestRow = -1, bestCol = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int moveVal = minimax(board, 0, 0);
                board[i][j] = ' ';  // Undo move
                
                if (moveVal > bestVal) {
                    bestRow = i;
                    bestCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    
    // Make the best move
    board[bestRow][bestCol] = 'X';
}

// Modify main to include AI player
int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    char currentPlayer = 'X';
    
    while (checkWinner(board) == ' ' && !isBoardFull(board)) {
        displayBoard(board);
        
        if (currentPlayer == 'X') {
            findBestMove(board);  // AI move
        } else {
            getPlayerMove(board, currentPlayer);  // Human move
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    displayBoard(board);
    char winner = checkWinner(board);
    if (winner != ' ') {
        printf("Player %c wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
