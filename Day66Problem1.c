#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Adjacency matrix
int adj[MAX][MAX];
int V;

// DFS function
bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // edge exists
            if (!visited[i]) {
                if (dfs(i, visited, recStack))
                    return true;
            }
            else if (recStack[i]) {
                return true; // cycle found
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to check cycle
bool hasCycle() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    V = 4;

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Example edges
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1; // cycle here

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
