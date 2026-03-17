#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val;
    
    // Read number of elements
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) != 1) break;

        // Dynamic memory allocation using malloc
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) return 1; // Check if memory allocation failed

        newNode->data = val;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Point to itself to start the circle
            tail = newNode;
        } else {
            tail->next = newNode; // Connect old tail to new node
            newNode->next = head; // Connect new node back to head
            tail = newNode;       // Update tail
        }
    }

    // Traversal: Using a do-while loop to handle the head node
    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d%s", temp->data, (temp->next != head ? " " : ""));
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    // Optional: Free memory (Good practice in C)
    if (head != NULL) {
        struct Node *current = head, *next;
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }

    return 0;
}
