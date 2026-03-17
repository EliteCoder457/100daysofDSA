
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper to get length of a list
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Main logic to find intersection
void findIntersection(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Advance the pointer of the longer list
    if (c1 > c2) {
        d = c1 - c2;
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        d = c2 - c1;
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    // Move both pointers until they meet
    // Note: In real scenarios, we compare addresses (ptr1 == ptr2)
    // Here, based on the problem example, we compare values
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

// Function to build list from input
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, val;

    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            append(&head1, val);
        }
    }

    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &val);
            append(&head2, val);
        }
    }

    findIntersection(head1, head2);

    return 0;
}
