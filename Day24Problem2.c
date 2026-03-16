struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to point to the head
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* current = &dummy;

    // Iterate as long as there is a node after the current one
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Target found: store it in temp, link past it, and free it
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); 
            
            // Note: We do NOT move 'current' here because the NEW
            // current->next needs to be checked in the next iteration.
        } else {
            // No match: just move to the next node
            current = current->next;
        }
    }

    return dummy.next;
}
