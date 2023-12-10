#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct Stack {
    int data[MAX_LENGTH];
    int head;
};

struct Stack *createStack() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->head = -1;
}

void push(struct Stack *stack, int data) {
    if(stack->head == -1) stack->head = 0;
    stack->data[stack->head] = data;
    stack->head++;
}

int pop(struct Stack *stack) {
    if(stack->head == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = stack->data[stack->head-1];
    printf("Head = %d\n", stack->head);
    stack->head--;
    return data;
}

int peek(struct Stack *stack) {
    if(stack->head == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->head-1];
}
int main() {
    struct Stack *stack = createStack();

    push(stack, 5);
    push(stack, 15);
    push(stack, 25);

    for(int i = 0; i < 10; i++) {
        printf("%d, ", stack->data[i]);
    }
    printf("\n");

    for(int i = 0; i < 10; i++) {
        printf("%d, ", stack->data[i]);
    }
    printf("\n");
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    for(int i = 0; i < 10; i++) {
        printf("%d, ", stack->data[i]);
    }
    printf("\n");
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
}