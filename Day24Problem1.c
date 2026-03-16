#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper to create and append nodes
void append(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to delete the first occurrence of a key
void deleteKey(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    // Case 1: The head node itself holds the key
    if (temp->data == key) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Case 2: Search for the key, keeping track of the previous node
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void printList(struct Node* head) {
    while (head) {
        printf("%d%s", head->data, (head->next ? " " : ""));
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val, key;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    scanf("%d", &key);

    deleteKey(&head, key);
    printList(head);

    return 0;
}
