#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int put_plate(struct Node **top_plate, int data) {
	struct Node *new_plate = malloc(sizeof(struct Node));
	new_plate->data = data;
	new_plate->next = *top_plate;
	*top_plate = new_plate;
	return 0;
}

int get_plate(struct Node **top_plate) {
	if(*top_plate == NULL) {
		return -1;
	}
	struct Node *old_plate = *top_plate;
	int data = old_plate->data;
	*top_plate = old_plate->next;
	free(old_plate);
	return data;
}

int main() {
	struct Node *top_plate = NULL;
	put_plate(&top_plate, 8);
	put_plate(&top_plate, 23);
	put_plate(&top_plate, 45);
	printf("%d\n", get_plate(&top_plate));
	printf("%d\n", get_plate(&top_plate));
	printf("%d\n", get_plate(&top_plate));
}