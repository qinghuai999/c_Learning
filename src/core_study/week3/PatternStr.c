#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * File: PatternStr.c
 * Author: Kiki Su
 * Created: 2026-01-28 08:11
 * Description: Find a special pattern and put the line in a new format.
 */
char *read_line(FILE *fp) {
    int c;
    size_t size = 0;
    size_t capacity = 32;
    char *buffer = (char *)malloc(capacity);
    if (!buffer) return NULL;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') break;
        buffer[size++] = (char)c;

        if (size >= capacity - 1) {
            capacity *= 2;
            char *tmp = (char *)realloc(buffer, capacity);
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


int find_pattern(char *filepath, char *pattern) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        return 1;
    }

    char *line = NULL;
    while ((line = read_line(fp)) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("[%s] %s", pattern, line);

            size_t len = strlen(line);
            if (len == 0 || line[len - 1] != '\n') {
                printf("\n");
            }
        }
        free(line);
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        return 1;
    }

    return find_pattern(argv[1], argv[2]);
}
