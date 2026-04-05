#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Queue implementation
int queue[MAX];
int front = 0, rear = 0;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Enqueue
void enqueue(int v) {
    queue[rear++] = v;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// BFS function
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front < rear) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
