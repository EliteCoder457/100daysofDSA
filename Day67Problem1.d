#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Stack
int stack[MAX];
int top = -1;

// Visited array
int visited[MAX];

// Function to create a new node
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
        visited[i] = 0;
    }
}

// Add edge (directed)
void addEdge(struct Graph* g, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = g->adj[src];
    g->adj[src] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(struct Graph* g, int v) {
    visited[v] = 1;

    struct Node* temp = g->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(g, temp->vertex);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological Sort
void topologicalSort(struct Graph* g) {
    for (int i = 0; i < g->V; i++) {
        if (!visited[i]) {
            dfs(g, i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
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
