#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * File: StringTest.c
 * Author: Kiki Su
 * Created: 2026-01-25 14:18
 * Description: 
 */
int my_str_len(char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

typedef struct String {
    char* array;
    int size;
} String;

char* my_mem_cpy(char* old) {
    int len = my_str_len(old);

    char *new = malloc((len + 1) * sizeof(char));

    if (new == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        new[i] = old[i];
    }

    new[len] = '\0';
    return new;
}

String init_string(char *input) {
    String s;
    s.size = my_str_len(input);
    s.array = my_mem_cpy(input);
    if (s.array == NULL) {
        s.size = 0;
    }
    return s;
}

void append_string(String *orig, String *extra) {
    orig -> array = realloc(orig -> array,
        (orig -> size + extra -> size + 1) * sizeof(char));

    strcat(orig -> array, extra -> array);

    orig -> size = orig -> size + extra -> size;
}

int main(int argc, char** argv) {
    String result = init_string("This isn't too bad");
    printf("array: %s\n", result.array);
    printf("size: %d\n", result.size);
    free(result.array);

    String a = init_string("Hello");
    String b = init_string("World!");

    append_string(&a, &b);

    printf("%s\n", a.array);
    printf("%d\n", a.size);
    free(a.array);
    free(b.array);
    return 0;
}

