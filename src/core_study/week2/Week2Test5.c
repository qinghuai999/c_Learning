#include <stdio.h>
/*
 * File: Week2Test5.c
 * Author: Kiki Su
 * Created: 2026-01-17 13:30
 * Description: 
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char** argv) {
    int x = 1;
    int y = 2;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}
