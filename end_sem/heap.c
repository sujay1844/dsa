#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define GET_LEFT_CHILD_IDX(idx) 2*idx + 1
#define GET_RIGHT_CHILD_IDX(idx) 2*idx + 2
#define GET_PARENT_IDX(idx) (idx-1) / 2

struct Heap {
    int data[MAX_LENGTH];
    int length;
};

struct Heap *createHeap() {
    struct Heap *heap = malloc(sizeof(struct Heap));
    heap->length = 0;
    return heap;
}

void heapifyUp(struct Heap *heap, int currentIdx) {
    if(currentIdx <= 0) return;

    int parentIdx = GET_PARENT_IDX(currentIdx);
    int parentValue = heap->data[parentIdx];
    int currentValue = heap->data[currentIdx];

    if(currentValue > parentValue) {
        heap->data[currentIdx] = parentValue;
        heap->data[parentIdx] = currentValue;

        heapifyUp(heap, parentIdx);
    }
}

void heapifyDown(struct Heap *heap, int currentIdx) {
    if (currentIdx >= heap->length) return;

    int leftIdx = GET_LEFT_CHILD_IDX(currentIdx);
    int rightIdx = GET_RIGHT_CHILD_IDX(currentIdx);
    int leftValue = heap->data[leftIdx];
    int rightValue = heap->data[rightIdx];
    int currentValue = heap->data[currentIdx];

    if(leftValue > rightValue) {
        heap->data[leftIdx] = currentValue;
        heap->data[currentIdx] = leftValue;
        heapifyDown(heap, leftIdx);
    } else if (leftValue < rightValue) {
        heap->data[rightIdx] = currentValue;
        heap->data[currentIdx] = rightValue;
        heapifyDown(heap, rightIdx);
    }
}

int insert(struct Heap *heap, int data) {
    if(heap->length == MAX_LENGTH) {
        printf("Heap is full\n");
        return -1;
    }
    heap->data[heap->length] = data;
    heapifyUp(heap, heap->length);
    heap->length++;

    return 0;
}

int delete(struct Heap *heap) {
    if(heap->length == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int data = heap->data[0];

    heap->data[0] = heap->data[heap->length - 1];
    heap->length--;
    heapifyDown(heap, 0);
    return data;
}

int *heapSort(int *arr, int length) {
    struct Heap *heap = createHeap();
    for(int i = 0; i < length; i++) {
        insert(heap, arr[i]);
    }

    for(int i = 0; i < length; i++) {
        arr[i] = delete(heap);
    }

    free(heap);
    return arr;
}

int main() {
    struct Heap *heap = createHeap();

    insert(heap, 5);
    insert(heap, 25);
    insert(heap, 15);
    insert(heap, 35);

    printf("%d\n", delete(heap));
    printf("%d\n", delete(heap));
    printf("%d\n", delete(heap));
    printf("%d\n", delete(heap));
    printf("%d\n", delete(heap));

    free(heap);

    int arr[] = {5, 25, 15, 35};
    printf("Before sorting: ");
    for(int i = 0; i < 4; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    int *sortedArray = heapSort(arr, 4);
    printf("After sorting: ");
    for(int i = 0; i < 4; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}