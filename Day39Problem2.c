#include <stdio.h>
#include <stdlib.h>

// Structure for heap node
typedef struct {
    int val;
    int freq;
} Node;

// Swap
void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Down (Min Heap based on freq)
void heapifyDown(Node heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;

    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Heapify Up
void heapifyUp(Node heap[], int i) {
    while (i > 0 && heap[i].freq < heap[(i-1)/2].freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Insert into heap
void insertHeap(Node heap[], int* size, Node val) {
    heap[*size] = val;
    heapifyUp(heap, *size);
    (*size)++;
}

// Extract Min
Node extractMin(Node heap[], int* size) {
    Node root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// MAIN FUNCTION
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    // Step 1: Frequency array (since range is limited)
    int offset = 10000;
    int freq[20001] = {0};

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + offset]++;
    }

    // Step 2: Min Heap
    Node heap[20001];
    int heapSize = 0;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            Node temp;
            temp.val = i - offset;
            temp.freq = freq[i];

            insertHeap(heap, &heapSize, temp);

            if (heapSize > k) {
                extractMin(heap, &heapSize);
            }
        }
    }

    // Step 3: Prepare result
    int* result = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].val;
    }

    *returnSize = k;
    return result;
}
