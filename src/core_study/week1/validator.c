#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 80

void wait_for_correct_password(void) {
	char buffer[MAX_BUFFER_SIZE];

	printf("Enter password: ");
	char psw[] = "password1\n";
	char* password = fgets(buffer, MAX_BUFFER_SIZE, stdin);
	while (password != NULL && strcmp(buffer, psw) != 0) {
		printf("Enter password: ");
		password = fgets(buffer, MAX_BUFFER_SIZE, stdin);
	}
	if (password == NULL) {
		printf("Login failed!\n");
	} else {
		printf("Password correct!\n");
	}
		

}

int main(int argc, char** argv) {
	wait_for_correct_password();
}
