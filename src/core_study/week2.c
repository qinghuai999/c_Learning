/*
 * File: week2.c
 * Author: Shiqi Su
 * Created: 2025-12-12 14:24
 * Description: 
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int total = 0;
    for (int i = 0; i < argc; ++i) {
        // 'man atoi' to search the introduction
        total += atoi(argv[i]);
    }
    printf("%d\n", total);
    return 0;
}
