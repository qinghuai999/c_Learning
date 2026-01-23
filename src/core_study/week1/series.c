#include <stdio.h>

void simple_number_printer(void) {
	for (int i = 0; i <= 10; i++) {
		printf("%d\n", i);
	}	
}

int main(int argc, char** argv) {
	simple_number_printer();
}
