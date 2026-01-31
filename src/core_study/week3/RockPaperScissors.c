/*
 * File: RockPaperScissors.c
 * Author: Kiki Su
 * Created: 2026-01-31 17:16
 * Description: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROUNDS 3

typedef enum {
    PAPER = 0,
    SCISSORS = 1,
    ROCK = 2,
    MOVE_COUNT = 3
} Move;

typedef enum {
    TIE = 0,
    PLAYER1_WIN = 1,
    PLAYER2_WIN = 2
} Outcome;

Move random_move() {
    return (Move)(rand() % MOVE_COUNT);
}
Outcome determine_winner(Move plr1, Move plr2) {
    if (plr1 == plr2) {
        return TIE;
    }

    if ((plr1 == PAPER && plr2 == ROCK) ||
        (plr1 == SCISSORS && plr2 == PAPER) ||
        (plr1 == ROCK && plr2 == SCISSORS)) {
        return PLAYER1_WIN;
    }
    return PLAYER2_WIN;
}

int generate_score(void) {
    int score = 0;

    for (int round = 0; round < NUM_ROUNDS; round++) {
        // What does it mean?
        Move p1 = random_move();
        Move p2 = random_move();
        Outcome out = determine_winner(p1, p2);

        if (out == PLAYER1_WIN) {
            score += 1;
        } else if (out == PLAYER2_WIN) {
            score -= 1;
        } else {
            score += 0;
        }

        return score;
    }
}

void print_score(int score) {
    if (score >= 2) {
        printf("Player 1 wins! \n");
    } else if (score <= -2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It was a draw!\n");
    }
}

int main(void) {
    srand((unsigned)time(NULL));

    int score = generate_score();
    print_score(score);

    return 0;
}