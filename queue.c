#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int front, rear;
    int arr[MAX_SIZE];
};

struct Queue *createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

void enqueue(struct Queue *queue, int data) {
    // If queue is empty
    if(queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    }
    queue->arr[queue->rear] = data;
    queue->rear++;
}

int dequeue(struct Queue *queue) {
    int data = queue->arr[queue->front];

    queue->front++;

    // Make queue empty
    if(queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    return data;
}

void print(struct Queue *queue) {
    if(queue->front == -1) return;

    for(int i = queue->front; i < queue->rear; i++) {
        printf("%d -> ", queue->arr[i]);
    }
    printf("\n");
}



int main() {
    struct Queue *queue = createQueue();
    enqueue(queue, 5);
    enqueue(queue, 69);
    enqueue(queue, 420);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 234);
    print(queue);
}