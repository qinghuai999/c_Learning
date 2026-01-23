#include <stdio.h>
#include "phraseC.h"

void phraseA();
void phraseB();

int main() {
	printf("Main program start\n");
	phraseA();
	phraseB();
	phraseC();
	
	printf("Main program end\n");

	return 0;
}
