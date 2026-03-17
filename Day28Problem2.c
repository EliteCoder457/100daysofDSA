#include <stdbool.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// Helper function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // 1. Find the middle of the list
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half
    // If list is odd, slow is at the exact middle; if even, slow is at start of second half
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;
    struct ListNode* tempSecond = secondHalf; // To keep track for comparison

    // 3. Compare the halves
    bool result = true;
    while (tempSecond != NULL) {
        if (firstHalf->val != tempSecond->val) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // 4. (Optional) Restore the list
    reverseList(secondHalf);

    return result;
}
