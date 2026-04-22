#include <stdio.h>

#define MAX 100
#define INF 999999

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize graph with INF
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }

    int visited[MAX] = {0};
    visited[1] = 1;   // start from node 1

    int edges = 0;
    int totalWeight = 0;

    while (edges < n - 1) {
        int min = INF;
        int x = -1, y = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        // Add edge to MST
        visited[y] = 1;
        totalWeight += min;
        edges++;
    }

    printf("%d", totalWeight);

    return 0;
}
