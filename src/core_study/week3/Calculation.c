/*
 * File: Calculation.c
 * Author: Kiki Su
 * Created: 2026-01-31 10:23
 * Description: Function pointer
 */
#include <stdio.h>
#include <stdlib.h>
double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double (*get_op(char c))(double, double) {
    switch (c) {
        case '+': return add;
        case '-': return sub;
        case '*': return mul;
        case '/': return divide;
        default: return NULL;
    }
}

int main(void) {
    double a, b;
    char c;

    if (scanf("%lf %lf %c", &a, &b, &c) != 3) {
        fprintf(stderr, "Usage: <num> <num> <op>\n");
        return 1;
    }
    double (*op)(double, double) = get_op(c);
    if (!op) {
        fprintf(stderr, "Unknow operator: %c\n", c);
        return 1;
    }
    double ans = op(a, b);
    printf("result: %.2f\n", ans);
    return 0;
}
