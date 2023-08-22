#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int id;
	char name[16];
	float gpa;
};

int main() {
	struct Student *student = malloc(sizeof(struct Student));

	student->id = 1;
	student->gpa = 9.9;
	strcpy(student->name, "Sujith");

	printf("\n");
	return 0;
}