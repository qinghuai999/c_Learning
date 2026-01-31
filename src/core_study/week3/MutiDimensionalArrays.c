#include <stdio.h>
#include <stdlib.h>
/*
 * File: MutiDimensionalArrays.c
 * Author: Kiki Su
 * Created: 2026-01-27 13:27
 * Description: Create a 2D Array and print it.
 */
#define EMPTY_CELL '_'
#define PLAYER_CELL 'X'

char **init_board(int rows, int cols) {
    // Which rows in heap
    char **board = malloc(rows * sizeof(char *));
    if (board == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        board[i] = malloc(cols * sizeof(char));
        if (!board[i]) {
            for (int k = 0; k < i; k++) {
                free(board[k]);
            }
            free(board);
            return NULL;
        }
        for (int j = 0; j < cols; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }
    return board;
}

void print_board(char **board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int rows = 5;
    int cols = 4;

    char **board = init_board(rows, cols);
    board[2][1] = PLAYER_CELL;
    print_board(board, rows, cols);
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}
