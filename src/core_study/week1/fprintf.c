#include <stdio.h>

void print_sum_better(int arg1, int arg2) {
	if (arg1 < 0 || arg2 < 0) {
		fprintf(stderr, "One or more of the numbers entered are not positive\n");
	}
	else printf("%d + %d = %d\n", arg1, arg2, (arg1 + arg2));
	
}

int main(void) {
	print_sum_better(10, 20);
	print_sum_better(30, 22);
	print_sum_better(-223, -500);
	return 0;
}
