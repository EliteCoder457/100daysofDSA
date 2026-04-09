#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Graph using adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
void initGraph(struct Graph* g, int V) {
    g->V = V;
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
    }
}

// Add edge
void addEdge(struct Graph* g, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = g->adj[src];
    g->adj[src] = newNode;
}

// Enqueue
void enqueue(int v) {
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// Topological Sort (Kahn’s Algorithm)
void topologicalSort(struct Graph* g) {
    int indegree[MAX] = {0};

    // Step 1: Calculate indegree
    for (int i = 0; i < g->V; i++) {
        struct Node* temp = g->adj[i];
        while (temp != NULL) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (int i = 0; i < g->V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: Process queue
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        count++;

        struct Node* temp = g->adj[current];
        while (temp != NULL) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) {
                enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }

    // Step 4: Check for cycle
    if (count != g->V) {
        printf("\nGraph has a cycle! No topological ordering possible.\n");
    }
}

// Main
int main() {
    struct Graph g;
    int V = 6;

    initGraph(&g, V);

    // Example DAG
    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);

    topologicalSort(&g);

    return 0;
}
