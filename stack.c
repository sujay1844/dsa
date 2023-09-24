#include <stdio.h>
#include <stdlib.h>

struct Plate {
	int data;
	struct Plate *below;
};

int put_plate(struct Plate **top_plate, int data) {
	struct Plate *new_plate = malloc(sizeof(struct Plate));
	new_plate->data = data;
	new_plate->below = *top_plate;
	*top_plate = new_plate;
	return 0;
}

int get_plate(struct Plate **top_plate) {
	if(*top_plate == NULL) {
		return -1;
	}
	struct Plate *old_plate = *top_plate;
	int data = old_plate->data;
	*top_plate = old_plate->below;
	free(old_plate);
	return data;
}

int main() {
	struct Plate *top_plate = NULL;
	put_plate(&top_plate, 8);
	put_plate(&top_plate, 23);
	put_plate(&top_plate, 45);
	printf("%d\n", get_plate(&top_plate));
	printf("%d\n", get_plate(&top_plate));
	printf("%d\n", get_plate(&top_plate));
}