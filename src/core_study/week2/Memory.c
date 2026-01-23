/*
 * File: Memory.c
 * Author: Kiki Su
 * Created: 2026-01-23 13:38
 * Description: 
 */

#include <stdio.h>

int *set_value(int *p) {
    *p = 5;
    return p;
}

int main() {
    int x = 0;
    int *ptr = &x;
    printf("Before: x = %d\n", x);

    int *returned = set_value(ptr);
    printf("After: x = %d\n", x);
    printf("Returned address == original address ? %s\n", (returned == ptr) ? "Yes" : "No");
}
