#include <stdio.h>

int sum(int a, int b) {
	int ans;
	ans = a + b;
	return ans;
}

int main(void) {
	printf("%d\n", sum(10, 15));
	return 0;
}
