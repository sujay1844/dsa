// Print string characer by character using pointer
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *str = "Hello World";
	char *ptr = str;

	while (*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}

	printf("\n");
	return 0;
}