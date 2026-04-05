#include <stdlib.h>

// Helper to find index in inorder
int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int* preorder, int* inorder, 
                                int preStart, int preEnd, 
                                int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = root->right = NULL;

    // Find root in inorder
    int inRoot = findIndex(inorder, inStart, inEnd, root->val);

    int leftSize = inRoot - inStart;

    // Build left subtree
    root->left = buildTreeHelper(preorder, inorder,
                                 preStart + 1,
                                 preStart + leftSize,
                                 inStart,
                                 inRoot - 1);

    // Build right subtree
    root->right = buildTreeHelper(preorder, inorder,
                                  preStart + leftSize + 1,
                                  preEnd,
                                  inRoot + 1,
                                  inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return buildTreeHelper(preorder, inorder, 
                           0, preorderSize - 1,
                           0, inorderSize - 1);
}
