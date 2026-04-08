#include <stdbool.h>
#include <stdlib.h>

#define MAX 2000

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// DFS function to detect cycle
bool dfs(int node, struct Node* adj[], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Create adjacency list
    struct Node* adj[MAX] = {NULL};

    // Build graph: b → a
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        // add edge b -> a
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = a;
        newNode->next = adj[b];
        adj[b] = newNode;
    }

    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    // Check all components
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return false; // cycle exists → cannot finish
        }
    }

    return true; // no cycle → can finish
}
