#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int do_operation(int num1, char operation, int num2) {
	if (operation == '+') {
		return num1 + num2;
	} else if (operation == '-') {
		return num1 - num2;
	} else if (operation == '*') {
		return num1 * num2;
	} else if (operation == '/') {
		return num1 / num2;
	} else {
		exit(3);
	}
}

int main(int argc, char** argv) {
	if (argc != 4) {
		return 1;
	}
	char operator = argv[1][0]; // Find the first character of that string;
	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);
	
	if (num1 <= 0 || num2 <= 0) {
		return 2;
	}

	int result = do_operation(num1, operator, num2);
	printf("%d %c %d = %d\n", num1, operator, num2, result);
}
