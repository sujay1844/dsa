#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int HEAP[MAX_LENGTH];
int length = 0;

int parent(int idx) {
    return (idx-1)/2;
}
int leftChild(int idx) {
    return idx*2 + 1;
}
int rightChild(int idx) {
    return idx*2 + 2;
}

void heapifyUp(int idx) {
    if(idx == 0) {
        return;
    }

    int value = HEAP[idx];
    int parentIdx = parent(idx);
    int parentValue = HEAP[parentIdx];

    if(parentValue < value) {
        HEAP[idx] = parentValue;
        HEAP[parentIdx] = value;

        heapifyUp(parent(idx));
    }
}

void heapifyDown(int idx) {
    if(idx == length) {
        return;
    }

    // Extracting requried indexes from heap
    int leftIdx = leftChild(idx);
    int rightIdx = rightChild(idx);

    // Extracting required values from heap
    int leftValue = HEAP[leftIdx];
    int rightValue = HEAP[rightIdx];
    int value = HEAP[idx];

    if(leftValue > rightValue && value > rightValue) {
        //Swapping parent and child
        HEAP[idx] = rightValue;
        HEAP[rightIdx] = value;
        // Recursively calling heapifyDown
        heapifyDown(rightIdx);
    } else if (rightValue > leftValue && value > leftValue) {
        //Swapping parent and child
        HEAP[idx] = leftValue;
        HEAP[leftIdx] = value;
        // Recursively calling heapifyDown
        heapifyDown(leftIdx);
    }
}

void insert(int value) {
    // Insert new element to last index of heap
    HEAP[length] = value;
    // Heapify up the heap
    heapifyUp(length);
    // Increase length to indicate new element
    length++;
}

int delete(int value) {
    if(length == 0) {
        return -1;
    }

    int output = HEAP[0];
    length--;

    if(length == 0) {
        HEAP[0] = 0;
        length = 0;
        return output;
    }

    HEAP[0] = HEAP[length];
    heapifyDown(0);
}

// Write a test case in main()
int main()
{
}