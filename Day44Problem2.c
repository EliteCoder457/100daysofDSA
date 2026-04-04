#include <stdlib.h>

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    struct TreeNode* stack[100];
    int top = -1, idx = 0;
    
    if (root != NULL) {
        stack[++top] = root;
    }
    
    while (top != -1) {
        struct TreeNode* node = stack[top--];
        result[idx++] = node->val;
        
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    
    *returnSize = idx;
    return result;
}
