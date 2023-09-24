#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAt(struct Node *tail, int pos, int data) {
    if(tail == NULL) {
        tail->data = data;
        tail->next = tail;
        return;
    }
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *traverse = tail;

    for(int i = 0; i < pos; i++) {
        traverse = traverse->next;
    }

    newNode->next = traverse->next;
    traverse->next = newNode;
}

int deleteAt(struct Node **tail, int pos) {
    if(*tail == NULL) {
        return -1;
    }
    if((*tail)->next == *tail) {
        int data = (*tail)->data;
        free(*tail);
        *tail = NULL;
        return data;
    }

    struct Node *traverse = *tail;

    for(int i = 0; i < pos; i++) {
        traverse = traverse->next;
    }
    struct Node *oldNode = traverse->next;
    traverse->next = traverse->next->next;
    int data = oldNode->data;
    free(oldNode);
    return data;
}

void print(struct Node *tail) {
    struct Node *traverse = tail;
    if(traverse == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d <-> ", traverse->data);
        traverse = traverse->next;
    } while(traverse != tail);
    printf("\n");
}

int main() {
    struct Node *tail = malloc(sizeof(struct Node));
    tail->data = 5;
    tail->next = tail;

    insertAt(tail, 0, 69);
    insertAt(tail, 0, 45);
    insertAt(tail, 0, 96);
    insertAt(tail, 2, 960);
    print(tail);
    tail = tail->next;
    print(tail);
    deleteAt(&tail, 2);
    print(tail);
    deleteAt(&tail, 0);
    print(tail);
    deleteAt(&tail, 0);
    print(tail);
    deleteAt(&tail, 0);
    print(tail);
    deleteAt(&tail, 0);
    print(tail);
}