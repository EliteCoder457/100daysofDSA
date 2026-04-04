#include <stdlib.h>

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    struct TreeNode* stack[100];
    int top = -1;
    int idx = 0;
    
    while (root != NULL || top != -1) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        result[idx++] = root->val;
        root = root->right;
    }
    
    *returnSize = idx;
    return result;
}
