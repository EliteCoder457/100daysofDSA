#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Dummy head helps simplify the code by providing a starting point
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* curr = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        // Get values from nodes, or 0 if the list has ended
        int v1 = (l1 != NULL) ? l1->val : 0;
        int v2 = (l2 != NULL) ? l2->val : 0;

        // Calculate sum and carry
        int sum = v1 + v2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        // Create new node for the result
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;
        
        curr->next = newNode;
        curr = newNode;

        // Move to the next nodes in the input lists
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return dummy.next;
}
