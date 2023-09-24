#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include time.h for random seed

#define MAX_LEVEL 5

struct SkipNode {
    int data;
    struct SkipNode *next;
    struct SkipNode *down;
};

void insert(struct SkipNode **head, int data) {
    struct SkipNode *current = *head;
    struct SkipNode *required_positions[MAX_LEVEL + 1];

    for(int i = 0; i <= MAX_LEVEL; i++) {
        required_positions[i] = NULL;
    }

    for(int level = MAX_LEVEL; level >= 0; level--) {
        while(current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        required_positions[level] = current;
        current = current->down;
    }

    int randomLevel = 0;
    while (randomLevel < MAX_LEVEL+1 && rand() % 2 == 0) {
        randomLevel++;
    }

    for(int i = 0; i <= randomLevel; i++) {
        struct SkipNode *newNode = malloc(sizeof(struct SkipNode));
        if (!newNode) {
            // Handle memory allocation failure
            // Free allocated memory and return
            return;
        }
        newNode->data = data;
        newNode->down = NULL;

        newNode->next = required_positions[i]->next;
        required_positions[i]->next = newNode;
        if(i > 0) {
            newNode->down = required_positions[i-1]->next;
        }
    }
}

void print(struct SkipNode *head) {
    struct SkipNode *v_traverse = head;
    while(v_traverse != NULL) {
        struct SkipNode *h_traverse = v_traverse;
        while(h_traverse != NULL) {
            printf("%d ", h_traverse->data);
            h_traverse = h_traverse->next;
        }
        printf("\n");
        v_traverse = v_traverse->down;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int headData = 2;
    struct SkipNode *head = malloc(sizeof(struct SkipNode));
    if (!head) {
        // Handle memory allocation failure and return
        return 1;
    }
    struct SkipNode *traverse = head;
    for(int i = 0; i <= MAX_LEVEL; i++) {
        traverse->data = headData;
        traverse->down = NULL; // Initialize the down pointer
        traverse->next = NULL; // Initialize the next pointer
        if (i < MAX_LEVEL) {
            struct SkipNode *lowerLevel = malloc(sizeof(struct SkipNode));
            if (!lowerLevel) {
                // Handle memory allocation failure
                // Free allocated memory and return
                return 1;
            }
            traverse->down = lowerLevel;
        }
        traverse = traverse->down;
    }

    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 9);
    insert(&head, 12);
    insert(&head, 32);
    insert(&head, 43);
    insert(&head, 51);
    insert(&head, 59);
    print(head);

    // Free allocated memory here when you're done with the skip list
    // ...

    return 0;
}
