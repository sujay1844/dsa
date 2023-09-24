#include <stdio.h>
#include <stdlib.h>

struct DLL {
    struct Node *head;
    struct Node *tail;
};

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtFront(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;

    newNode->next = *head;
    if(*tail == NULL)
        *tail = newNode;
    if(*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

void insertAtEnd(struct Node **head, struct Node **tail, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    newNode->prev = *tail;
    if(*head == NULL)
        *head = newNode;
    if(*tail != NULL) 
        (*tail)->next = newNode;

    *tail = newNode;
}

int deleteAtFront(struct Node **head, struct Node **tail) {
    if(*head == NULL) return -1;

    struct Node *frontNode = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    int data = frontNode->data;
    free(frontNode);
    return data;
}

int deleteAtEnd(struct Node **head, struct Node **tail) {
    if(*tail == NULL) return -1;

    struct Node *lastNode = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    int data = lastNode->data;
    free(lastNode);
    return data;
}

int print(struct Node **head, struct Node **tail) {
    struct Node *traverse = *head;
    while(traverse != NULL) {
        printf("%d <-> ", traverse->data);
        traverse = traverse->next;
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    insertAtEnd(&head, &tail, 69);
    insertAtEnd(&head, &tail, 420);
    insertAtEnd(&head, &tail, 10);
    insertAtFront(&head, &tail, 40);
    insertAtFront(&head, &tail, 50);
    deleteAtEnd(&head, &tail);
    deleteAtFront(&head, &tail);
    print(&head, &tail);
}