#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int append(struct Node **head, int data) {
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;

	if(*head == NULL) {
		*head = new_node;
		return 0;
	}

	struct Node *traverse = *head;
	while(traverse->next != NULL) {
		traverse = traverse->next;
	}
	traverse->next = new_node;

	return 0;
}

int prepend(struct Node **head, int data) {
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;

	new_node->next = *head;
	*head = new_node;

	return 0;
}

int print_list(struct Node **head) {
	if(*head == NULL) return 1;

	struct Node *traverse = *head;
	while(traverse->next != NULL) {
		printf("%d->", traverse->data);
		traverse = traverse->next;
	}
	printf("%d\n", traverse->data);

	return 0;
}

int pop(struct Node **head) {
	if(*head == NULL) return 1;

	if((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return 0;
	}

	struct Node *traverse = *head;
	while(traverse->next->next != NULL) {
		traverse = traverse->next;
	}

	free(traverse->next);
	traverse->next = NULL;

	return 0;
}

int popleft(struct Node **head) {
	if(*head == NULL) return 1;
	struct Node *temp = head;
	*head = (*head)->next;
	free(temp);
	return 0;
}

int pop(struct Node **head, int index) {
	if(*head == NULL) return 1;

	if(index == 0) {
		return popleft(*head);
	}

	int i = 0;
	struct Node *traverse = *head;
	while (traverse != NULL && i < index) {
		traverse = traverse->next;
		i++;
	}
	if(traverse == NULL || traverse->next == NULL) {
		return 1;
	}
	struct Node *temp = traverse->next;
	traverse->next = temp->next;
	free(temp);

	return 0;
}

int delete_list(struct Node **head) {
	while(pop(head) == 0);
}

int print_list_as_table(struct Node **head) {

	if(*head == NULL) return 1;

	struct Node *traverse = *head;
	while(traverse != NULL) {
		printf("%p\t%d\t%p\n", traverse, traverse->data, traverse->next);
		traverse = traverse->next;
	}

	return 0;
}

int insert(struct Node **head, int index) {
	int i = 0;
	if(*head == NULL) return 1;

	struct Node *traverse = *head;
	while(traverse->next != NULL) {
		if(i == index) {
			// insert
		}
		i++;
		traverse = traverse->next;
	}
}

int search(struct Node **head, int search_term) {
	if(*head == NULL) return -1;

	int i = 0;
	struct Node *traverse = *head;
	while(traverse != NULL) {
		if(traverse->data == search_term)
			return i;
		traverse = traverse->next;
		i++;
	}
	return -1;
}

int search_rec(struct Node **head, int search_term, int index) {
	if (*head == NULL)
		return -1;
	if ((*head)->data == search_term)
		return index;
	return search_rec((*head)->next, search_term, index + 1);
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
	print_list_as_table(&head);
	delete_list(&head);
}