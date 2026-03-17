#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // Defining a maximum size for the array

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        // Stack Overflow - not explicitly required by your prompt but good practice
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        return; 
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n, choice, value;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    }

    return 0;
}
