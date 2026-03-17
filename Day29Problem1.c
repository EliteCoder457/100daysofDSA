#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    // Build the initial linear linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    k = k % n; // Handle cases where k >= n

    if (k > 0) {
        // Step 1: Make it circular
        tail->next = head;

        // Step 2: Find the new tail 
        // It is at (n - k - 1) steps from the current head
        struct Node* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }

        // Step 3: Break the circle
        head = newTail->next;
        newTail->next = NULL;
    }

    // Print the rotated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next != NULL ? " " : ""));
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
