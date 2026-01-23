/*
 * File: Week2Test4.c
 * Author: Shiqi Su
 * Created: 2026-01-06 14:02
 * Description: 
 */
#include <stdio.h>
#include <stdlib.h>
int* func(void) {
    int* p = (int*)malloc(sizeof(int));
    
    printf("%p %d\n", p, *p);
    *p = 34;
    printf("%p %d\n", p, *p);
    free(p);

    p = (int*)malloc(sizeof(int));
    printf("%p %d\n", p, *p);
    *p = 2310;
    printf("%p %d\n", p, *p);
    return p;
}

int main(int argc, char** argv) {
    int* p2 = func();
    int* p3 = p2;
    free(p2);
    printf("%p %d\n", p3, *p3);
    return 0;
}


