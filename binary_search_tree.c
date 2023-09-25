#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int data) {
    if(root == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        return newNode;
    }
    if(root->data > data) {
        root->left = insert(root->left, data);
    } else if(root->data < data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrder(struct Node *root) {
    if(root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int search(struct Node *root, int term) {
    if(root == NULL) {
        return 0;
    }
    if(root->data == term) {
        return 1;
    } else if(root->data > term) {
        return search(root->left, term);
    } else if(root->data < term) {
        return search(root->right, term);
    }
}

int main() {
    int arr[] = {5, 1, 3, 4, 6, 7, 2};
    struct Node *root = NULL;
    for(int i = 0; i < 7; i++) {
        root = insert(root, arr[i]);
    }
    inOrder(root);
    printf("\n");
    printf("%d was %s\n", 3, search(root, 3) ? "found" : "not found");
    printf("%d was %s\n", 9, search(root, 9) ? "found" : "not found");
}