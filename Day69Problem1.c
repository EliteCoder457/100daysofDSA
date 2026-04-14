#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Create new adjacency node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->heap[left].dist < heap->heap[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->heap[right].dist < heap->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->heap[i], &heap->heap[smallest]);
        heapify(heap, smallest);
    }
}

// Insert into heap
void push(struct MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->heap[i].vertex = v;
    heap->heap[i].dist = dist;

    while (i && heap->heap[(i-1)/2].dist > heap->heap[i].dist) {
        swap(&heap->heap[i], &heap->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract min
struct HeapNode pop(struct MinHeap* heap) {
    struct HeapNode root = heap->heap[0];
    heap->heap[0] = heap->heap[--heap->size];
    heapify(heap, 0);
    return root;
}

// Check empty
int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

// Dijkstra function
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];

    for (int i = 0; i < graph->V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap heap;
    heap.size = 0;

    push(&heap, src, 0);

    while (!isEmpty(&heap)) {
        struct HeapNode node = pop(&heap);
        int u = node.vertex;

        struct Node* temp = graph->adj[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < graph->V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    struct Graph graph;
    graph.V = 5;

    for (int i = 0; i < graph.V; i++)
        graph.adj[i] = NULL;

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 4, 1, 3);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 4, 3, 2);
    addEdge(&graph, 3, 2, 4);
    addEdge(&graph, 2, 3, 6);

    int source = 0;
    dijkstra(&graph, source);

    return 0;
}
