#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency list
int *adj[MAX];
int size[MAX];      // number of neighbors
bool visited[MAX];

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }
    }
    return false;
}

// Function to detect cycle
bool hasCycle(int V) {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4, E = 4;

    int edges[4][2] = {{0,1}, {0,2}, {1,2}, {2,3}};

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
        size[i] = 0;
    }

    // Build graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    if (hasCycle(V))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
