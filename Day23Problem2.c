/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // If list is empty or has only one node without a loop
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Move fast by 2 and slow by 1
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // If they meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If we exit the loop, fast reached the end (no cycle)
    return false;
}
