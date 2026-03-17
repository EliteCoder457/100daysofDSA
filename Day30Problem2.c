#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Since C doesn't have a built-in stack, we'll use arrays as stacks.
    // Constraints say max 100 nodes.
    int s1[100], s2[100];
    int top1 = -1, top2 = -1;

    // Push l1 onto stack
    while (l1) {
        s1[++top1] = l1->val;
        l1 = l1->next;
    }
    // Push l2 onto stack
    while (l2) {
        s2[++top2] = l2->val;
        l2 = l2->next;
    }

    struct ListNode* head = NULL;
    int carry = 0;

    // Process stacks
    while (top1 >= 0 || top2 >= 0 || carry > 0) {
        int v1 = (top1 >= 0) ? s1[top1--] : 0;
        int v2 = (top2 >= 0) ? s2[top2--] : 0;

        int sum = v1 + v2 + carry;
        carry = sum / 10;
        
        // Create new node and insert at the FRONT
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = head;
        head = newNode;
    }

    return head;
}
