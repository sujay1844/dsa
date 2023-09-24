#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insert(struct Node *ptr, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = ptr->next;
    newNode->prev = ptr;

    ptr->next = newNode;
    newNode->next->prev = newNode;
}
void print(struct Node *ptr) {
    struct Node *traverse = ptr;
    if(traverse == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d <-> ", traverse->data);
        traverse = traverse->next;
    } while(traverse != ptr);
    printf("\n");
}

int main() {
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = 5;
    ptr->next = ptr;
    ptr->prev = ptr;
    print(ptr);
    insert(ptr, 34);
    print(ptr);
    insert(ptr, 69);
    print(ptr);
    return 0;
}