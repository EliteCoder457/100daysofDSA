#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Read number of elements to push
    if (scanf("%d", &n) != 1) return 0;

    // Dynamic memory allocation for the stack based on n
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    // Push n elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }

    // Read number of pops
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        if (top != -1) {
            top--; 
        }
    }

    // Print remaining stack elements from top to bottom
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");

    // Clean up memory
    free(stack);

    return 0;
}
