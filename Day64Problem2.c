#include <stdlib.h>

typedef struct {
    int r, c;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    Node queue[100];
    int front = 0, rear = 0;

    int fresh = 0;

    // Step 1: Add all rotten oranges to queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // If no fresh oranges
    if (fresh == 0) return 0;

    int minutes = 0;

    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // BFS
    while (front < rear) {
        int size = rear - front;
        int infected = 0;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nr = curr.r + directions[d][0];
                int nc = curr.c + directions[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear++] = (Node){nr, nc};
                    fresh--;
                    infected = 1;
                }
            }
        }

        if (infected) minutes++;
    }

    return (fresh == 0) ? minutes : -1;
}
