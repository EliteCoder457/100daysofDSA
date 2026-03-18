#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Deque structure
typedef struct {
    struct Node* front;
    struct Node* rear;
    int size;
} Deque;

// Create deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Check empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// Size
int size(Deque* dq) {
    return dq->size;
}

// Push front
void push_front(Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

// Push back
void push_back(Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

// Pop front
void pop_front(Deque* dq) {
    if (empty(dq)) return;

    struct Node* temp = dq->front;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    dq->size--;
}

// Pop back
void pop_back(Deque* dq) {
    if (empty(dq)) return;

    struct Node* temp = dq->rear;

    if (dq->front == dq->rear) {
        dq->front = dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    dq->size--;
}

// Front element
int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->front->data;
}

// Back element
int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->rear->data;
}

// Clear deque
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Display deque
void display(Deque* dq) {
    struct Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse deque
void reverse(Deque* dq) {
    struct Node* temp = NULL;
    struct Node* curr = dq->front;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // swap front and rear
    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}
