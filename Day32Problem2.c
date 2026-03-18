#include <stdlib.h>
#include <limits.h>

// Helper structure to store the value and the current minimum
typedef struct {
    int val;
    int min;
} Node;

typedef struct {
    Node* data;
    int top;
    int capacity;
} MinStack;

/** Initializes the stack object */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 30000; // Based on constraints
    obj->data = (Node*)malloc(sizeof(Node) * obj->capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->data[obj->top].val = val;
    
    // If it's the first element, it is the min.
    // Otherwise, compare val with the min of the element below it.
    if (obj->top == 0) {
        obj->data[obj->top].min = val;
    } else {
        int currentMin = obj->data[obj->top - 1].min;
        obj->data[obj->top].min = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}
