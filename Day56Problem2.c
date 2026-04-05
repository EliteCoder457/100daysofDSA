bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // Both null → symmetric
    if (t1 == NULL && t2 == NULL)
        return true;

    // One null → not symmetric
    if (t1 == NULL || t2 == NULL)
        return false;

    // Check values + mirror structure
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}
