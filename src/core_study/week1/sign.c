#include <stdio.h>

void print_sign(int arg) {
	if (arg > 0) {
		printf("This number is positive\n");
	} else if (arg == 0) {
		printf("This number is zero\n");
	} else {
		printf("This number is negative\n");
	}
}

int main(void) {
	print_sign(0);
	print_sign(1);
	print_sign(-1);
	return 0;
}
