// Swap two variable using pointers

#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int *ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main() {
	int a = 10, b = 20;
	printf("Before swap: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);

	printf("\n");
	return 0;
}