// Converting postfix to infix using expression tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct StackNode {
    struct Node *treeNode;
    struct StackNode *next;
};

int isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

struct Node *createNode(char data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct StackNode *createStackNode(struct Node *node) {
    struct StackNode *newNode = malloc(sizeof(struct StackNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    return newNode;
}

int push(struct StackNode **head, struct Node *node) {
    struct StackNode *newStackNode = createStackNode(node);
    newStackNode->next = *head;
    *head = newStackNode;
}

struct Node *pop(struct StackNode **head) {
    struct StackNode *lastStackNode = *head;
    *head = (*head)->next;
    return lastStackNode->treeNode;
}

int printTree(struct Node *root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) {
        printf("%c", root->data);
        return 0;
    }

    printf("(");
    printTree(root->left);
    printf("%c", root->data);
    printTree(root->right);
    printf(")");
}

int main() {
    char input[MAX_LENGTH] = "abc*+";

    printf("\nPostfix:\n%s\n", input);
    // scanf("%s", input);

    struct StackNode *head = malloc(sizeof(struct StackNode));
    for(int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        if(currentChar == ' ') continue;
        struct Node *current = createNode(currentChar);
        if(isOperand(current->data)) {
            push(&head, current);
        } else {
            struct Node *rightNode = pop(&head);
            struct Node *leftNode = pop(&head);
            current->right = rightNode;
            current->left = leftNode;
            push(&head, current);
        }
    }
    printf("\nInfix:\n");
    printTree(head->treeNode);

    printf("\n");
    return 0;
}