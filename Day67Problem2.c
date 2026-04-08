#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
    // Adjacency list
    int* adj[MAX];
    int adjSize[MAX] = {0};

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
    }

    // Indegree array
    int indegree[MAX] = {0};

    // Build graph: b → a
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        adj[b][adjSize[b]++] = a;
        indegree[a]++;
    }

    // Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Result array
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // If cycle exists
    if (count != numCourses) {
        *returnSize = 0;
        return (int*)malloc(0);
    }

    *returnSize = count;
    return result;
}
