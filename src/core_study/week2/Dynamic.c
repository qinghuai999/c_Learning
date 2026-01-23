/*
 * File: Dynamic.c
 * Author: Kiki Su
 * Created: 2026-01-23 13:54
 * Description: 
 */
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 80

int main(int argc, char** argv) {
    // 1> malloc a 1-element int array
    int size = 1;
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("malloc");
        return 1;
    }

    // 2> put argc into arr[0]
    arr[0] = argc;

    // 3> read lines, parse int, stop on 0 or invalid, else grow and store
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
        int num;
        int ok = sscanf(buffer, "%d", &num);

        if (ok != 1 || num == 0) {
            break;
        }

        int *tmp = realloc(arr, (size + 1) * sizeof(int));
        if (tmp == NULL) {
            free(arr);
            perror("realloc");
            return 1;
        }
        arr = tmp;

        arr[size] = num;
        size++;
    }

    // 4> print in reverse order (each on its own line)
    for (int i = size - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}
