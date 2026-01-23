/*
 * File: Week2Test3.c
 * Author: Shiqi Su
 * Created: 2025-12-12 17:40
 * Description: 
 */
#include <stdio.h>
#include <stdlib.h>
void func(void) {
    int* p = (int*)malloc(sizeof(int));
    printf("%p %d\n", p, *p);
    *p = 34;
    printf("%p %d\n", p, *p);
    p = (int*)malloc(sizeof(int));
    printf("%p %d\n", p, *p);
}

int main(int argc, char** argv) {
    func();
    return 0;
}
