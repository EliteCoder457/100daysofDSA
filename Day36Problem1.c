#include <stdio.h>

#define MAX 100

int q[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x, int size) {
    if ((rear + 1) % size == front) {
        // Queue full (not needed here since n is fixed)
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    q[rear] = x;
}

// Dequeue
void dequeue(int size) {
    if (front == -1) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

// Display
void display(int size) {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
}

// Driver
int main() {
    int n, m, x;

    scanf("%d", &n);

    // enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x, MAX);
    }

    scanf("%d", &m);

    // dequeue m elements
    for (int i = 0; i < m; i++) {
        dequeue(MAX);
    }

    display(MAX);

    return 0;
}
