#include <limits.h>
#include <stdlib.h>

#define MAX 105

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

// Min heap node
struct HeapNode {
    int node, dist;
};

struct HeapNode heap[MAX * 100];
int size;

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size++;

    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify
void heapify(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;

    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Pop min
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Main function
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {

    // Initialize adjacency list
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    // Build graph
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        addEdge(u, v, w);
    }

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    // Dijkstra
    size = 0;
    dist[k] = 0;
    push(k, 0);

    while (size > 0) {
        struct HeapNode curr = pop();
        int u = curr.node;
        int d = curr.dist;

        if (d > dist[u]) continue;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Find max distance
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}
