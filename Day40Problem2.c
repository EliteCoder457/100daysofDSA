#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int n, int* returnSize) {
    
    int* result = (int*)calloc(n, sizeof(int)); // initialized with 0
    int* stack = (int*)malloc(n * sizeof(int)); // stack for indices
    int top = -1;

    for (int i = 0; i < n; i++) {

        // Resolve previous smaller temps
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            result[idx] = i - idx;
        }

        // Push current index
        stack[++top] = i;
    }

    *returnSize = n;
    free(stack);
    return result;
}
