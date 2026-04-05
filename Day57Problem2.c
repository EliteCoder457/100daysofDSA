struct TreeNode* prev = NULL;

void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    // Reverse preorder
    flatten(root->right);
    flatten(root->left);

    // Rewire pointers
    root->right = prev;
    root->left = NULL;

    // Move prev
    prev = root;
}
