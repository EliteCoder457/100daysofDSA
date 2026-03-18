#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push function
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop function
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

// Function to check if string is number
int isNumber(char* str) {
    if (*str == '-' && *(str+1) != '\0') str++; // handle negative numbers
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp[]) {
    struct Node* stack = NULL;
    int i = 0;

    while (exp[i] != NULL) {
        
        if (isNumber(exp[i])) {
            push(&stack, atoi(exp[i]));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (exp[i][0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&stack, result);
        }
        i++;
    }

    return pop(&stack);
}

// Driver code
int main() {
    char* exp[] = {"2", "3", "1", "*", "+", "9", "-", NULL};

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
