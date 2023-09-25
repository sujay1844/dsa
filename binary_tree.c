#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int idx = -1;
struct Node *build(int *arr, int n) {
    idx++;
    if(idx == n) {
        return NULL;
    }
    if (arr[idx] == -1) {
        return NULL;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = arr[idx];
    newNode->left = build(arr, n);
    newNode->right = build(arr, n);

    return newNode;
}

int countNodes(struct Node *node) {
    if(node == NULL) return 0;

    return countNodes(node->left) + countNodes(node->right) + 1;
}

int countLeaves(struct Node *node) {
    if(node == NULL) return 0;

    // Check if leaf node
    if(node->left == NULL && node->right == NULL) return 1;

    return countLeaves(node->left) + countLeaves(node->right);
}

int getLeaves(struct Node *node, int *leaves, int idx) {
    if(node == NULL) return idx;

    // Check if leaf node
    if(node->left == NULL && node->right == NULL) {
        leaves[idx] = node->data;
        idx++;
    }
    idx = getLeaves(node->left, leaves, idx);
    idx = getLeaves(node->right, leaves, idx);
    return idx;
}

int getHeight(struct Node *node) {
    if(node == NULL) return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int getDiameter(struct Node *node) {
    if(node == NULL) return 0;

    int leftDiameter = getDiameter(node->left);
    int rightDiameter = getDiameter(node->right);
    int diameterThroughRoot = getHeight(node->left) + getHeight(node->right) + 1;

    int max = 0;
    if(leftDiameter > max) max = leftDiameter;
    if(rightDiameter > max) max = rightDiameter;
    if(diameterThroughRoot > max) max = diameterThroughRoot;
}

int main() {
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    struct Node *root = build(nodes, 13);

    printf("%d\n", root->data);
    printf("%d\n", root->left->right->data);
    printf("Number of nodes: %d\n", countNodes(root));

    int numberOfLeaves = countLeaves(root);
    printf("Number of leaves: %d\n", numberOfLeaves);
    int leaves[numberOfLeaves];
    getLeaves(root, leaves, 0);
    printf("Leaves: ");
    for(int i = 0; i < numberOfLeaves; i++) {
        printf("%d ", leaves[i]);
    }
    printf("\n");
    printf("Height: %d\n", getHeight(root));
    printf("Diameter: %d\n", getDiameter(root));

}