/*
 * File: read.c
 * Author: Kiki Su
 * Created: 2026-01-27 14:20
 * Description: Exercise I/O
 */

#include <stdio.h>
#include <stdlib.h>

char *read_line(FILE *fp) {
    int c;
    int size = 0;
    int capacity = 16;

    char *buffer = malloc(capacity);
    if (!buffer) return NULL;
    // EOF is usually -1, which does not fit in an unsigned char.
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') break;
        buffer[size++] = (char) c;

        // Grow buffer if needed
        if (size >= capacity - 1) {
            capacity *= 2;
            char *tmp = realloc(buffer, capacity);
            if (!tmp) {
                free(buffer);
                return NULL;
            }
            buffer = tmp;
        }
    }

    if (size == 0 && c == EOF) {
        free(buffer);
        return NULL;
    }
    buffer[size] = '\0';
    return buffer;
}
//
// int main(int argc, char **argv) {
//     if (argc < 2) {
//         printf("Usage: %s filename\n", argv[0]);
//         return 1;
//     }
//
//     FILE *fp = fopen(argv[1], "r");
//     if (!fp) {
//         perror("Opening file");
//         return 1;
//     }
//
//     int sum = 0;
//     for (int i = 0; i < 3; i++) {
//         char *line = read_line(fp);
//         if (!line) break;
//         printf("%s\n", line);
//         free(line);
//     }
//
//     fclose(fp);
//     return 0;
// }
