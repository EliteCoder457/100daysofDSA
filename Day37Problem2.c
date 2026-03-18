#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(KthLargest* obj, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (obj->heap[parent] > obj->heap[i]) {
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(KthLargest* obj, int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Create
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;
    obj->k = k;

    // Insert initial elements
    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

// Add element
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } 
    else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0]; // kth largest
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
