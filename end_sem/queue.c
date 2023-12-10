#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 5

struct Q {
    int data[MAX_LENGTH];
    int head, tail;
};

struct Q *createQueue() {
    struct Q *q = malloc(sizeof(struct Q));
    q->head = 0;
    q->tail = 0;
}

int enq(struct Q *q, int data) {
    if((q->tail + 1) % MAX_LENGTH == q->head) {
        printf("\nQueue is full\n");
        return -1;
    }

    q->data[q->tail] = data;

    q->tail = (q->tail + 1) % MAX_LENGTH;

    return 0;
}

int deq(struct Q *q) {
    if(q->head == q->tail) {
        printf("\nQueue is empty\n");
        return -1;
    }

    int data = q->data[q->head];

    q->head = (q->head + 1) % MAX_LENGTH;

    return data;
}

int main() {
    struct Q *queue = createQueue();

    printf("Enqueue: %d\n", 10);
    enq(queue, 10);
    printf("Enqueue: %d\n", 20);
    enq(queue, 20);
    printf("Enqueue: %d\n", 30);
    enq(queue, 30);

    printf("Dequeued: %d\n", deq(queue));
    printf("Dequeued: %d\n", deq(queue));
    printf("Enqueue: %d\n", 40);
    enq(queue, 40);
    printf("Enqueue: %d\n", 50);
    enq(queue, 50);
    printf("Enqueue: %d\n", 60);
    enq(queue, 60);
    printf("Enqueue: %d\n", 70);
    enq(queue, 70);
    printf("Dequeued: %d\n", deq(queue));
    printf("Dequeued: %d\n", deq(queue));
    printf("Dequeued: %d\n", deq(queue));
    printf("Dequeued: %d\n", deq(queue));
    printf("Dequeued: %d\n", deq(queue));
    
    free(queue); // Free allocated memory
    return 0;
}