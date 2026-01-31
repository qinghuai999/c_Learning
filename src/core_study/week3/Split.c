/*
 * File: Split.c
 * Author: Kiki Su
 * Created: 2026-01-27 15:49
 * Description: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Read.h"

char **separate_line(char *line, int *word_count) {
    // 1. strlen -> counts how many characters appear before the
    // null terminator '\0'
    char *copy = malloc(strlen(line) + 1);
    // 2. strcpy -> duplicate the content from line to 'copy'
    strcpy(copy, line);
    char **words = NULL;
    int count = 0;

    char *token = strtok(copy, " ");
    while (token != NULL) {
        words = realloc(words, sizeof(char*) * (count + 1));
        words[count] = malloc(strlen(token) + 1);
        strcpy(words[count], token);

        count++;
        token = strtok(NULL, " ");
    }
    *word_count = count;
    free(copy);
    return words;
}

int main(int argc, char **argv) {
    //
    char *line = read_line(stdin);
    int n;
    char **words = separate_line(line, &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        sum += atoi(words[i]);
        free(words[i]);
    }
    printf("equals: %d\n", sum);
    free(words);

    // int a, b;
    // scanf("%d %d", &a, &b);
    // printf("add: %d %d\n", a, b);
    // printf("equals: %d\n", a + b);
    // return 0;
}
