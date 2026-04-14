#include <stdio.h>
#include <limits.h>

#define MAX 1000

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int source) {
    int dist[MAX];

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Step 2: Relax edges (n-1 times)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 4: Print distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n = 5; // vertices
    int m = 8; // edges

    struct Edge edges[] = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    int source = 0;

    bellmanFord(n, m, edges, source);

    return 0;
}
