#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];

// DFS function
bool dfs(int node, int parent, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

// Function to check cycle
void hasCycle(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

// Driver code
int main() {
    int n = 5; // number of vertices

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Add edges (undirected)
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][1] = adj[1][4] = 1; // creates cycle

    hasCycle(n);

    return 0;
}
