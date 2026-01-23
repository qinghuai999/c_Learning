/*
 * File: CppBasicGrammar.c
 * Author: Shiqi Su
 * Created: 2025-07-24 13:48
 * Description: Learning Basic C Grammar
 */

#include<stdio.h>
int main(int argc, char** argv) {
    for (int i = 0; i < argc; ++i) {
        printf("%s", argv[i]);
    }
    printf("\n");
    return 0;
}