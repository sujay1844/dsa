#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int append(struct Node **head, int data) {

	if (*head == NULL || (*head)->next == NULL) {

		struct Node *new_node = malloc(sizeof(struct Node));
		new_node->data = data;

		if (*head == NULL) {
			*head = new_node;
		}
		else {
			(*head)->next = new_node;
		}
		return 0;
	}
	return append(&(*head)->next, data);
}

int prepend(struct Node **head, int data) {
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;

	new_node->next = *head;
	*head = new_node;

	return 0;
}

int print(struct Node **head) {
	if(*head == NULL) {
		printf("\n");
		return 0;
	};

	printf("%d->", (*head)->data);
	
	return print(&(*head)->next);
}

int pop(struct Node **head) {
	if(*head == NULL) return 1;

	if((*head)->next == NULL) {
		*head = NULL;
		return 0;
	}

	if((*head)->next->next == NULL) {
		free((*head)->next);
		(*head)->next = NULL;
		return 0;
	}

	return pop(&(*head)->next);
}

int popleft(struct Node **head) {
	if(*head == NULL) return 1;

	struct Node *temp = *head;
	*head = (*head)->next;
	free(temp);

	return 0;
}

int delete(struct Node **head) {
	if(*head == NULL) return 0;
	popleft(head);
	return delete(head);
}

int search(struct Node **head, int search_term, int index) {
	if (*head == NULL)
		return -1;

	if ((*head)->data == search_term)
		return index;

	return search(&(*head)->next, search_term, index + 1);
}

int main() {
	struct Node *head = NULL;
	prepend(&head, 9);
	pop(&head);
	prepend(&head, 7);
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	pop(&head);
	print(&head);
	delete(&head);

}