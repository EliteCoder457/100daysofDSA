#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

// Create
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

// Push to queue
void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

// Helper: transfer s1 → s2
void transfer(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj->s2[++obj->top2] = obj->s1[obj->top1--];
    }
}

// Pop
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        transfer(obj);
    }
    return obj->s2[obj->top2--];
}

// Peek
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        transfer(obj);
    }
    return obj->s2[obj->top2];
}

// Empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

// Free memory
void myQueueFree(MyQueue* obj) {
    free(obj);
}
