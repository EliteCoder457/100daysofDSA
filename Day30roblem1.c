#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new term
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        
        struct Node* newNode = createNode(c, e);
        
        // Simple insertion at end (assuming input is sorted by exponent)
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Traversal and Formatting
    struct Node* temp = head;
    while (temp != NULL) {
        // 1. Print the coefficient and variable
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // 2. Print the separator " + " if there is a next term
        if (temp->next != NULL) {
            printf(" + ");
        }
        
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
