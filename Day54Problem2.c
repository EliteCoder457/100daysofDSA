int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        (*returnColumnSizes)[level] = size;
        result[level] = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // Decide position based on direction
            int index = leftToRight ? i : (size - 1 - i);
            result[level][index] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        leftToRight = !leftToRight; // flip direction
        level++;
    }

    *returnSize = level;
    return result;
}
