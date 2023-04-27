/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void traverse(struct TreeNode* curr, int*** ans, int level, int* deepest, int* returnSize, int** returnColumnSizes) {
    if (!curr) {
        return;
    }
    traverse(curr->left, ans, level+1, deepest, returnSize, returnColumnSizes);
    traverse(curr->right, ans, level+1, deepest, returnSize, returnColumnSizes);
    if (level > *deepest) {
        *deepest = level;
        if (level >= *returnSize) {
            int old_size = *returnSize;
            while (*returnSize < level)
                *returnSize <<= 1;
            int delta = (*returnSize)-old_size;
            *ans = realloc(*ans, (*returnSize)*sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize)*sizeof(int));
            memset(*ans+old_size, NULL, delta*sizeof(int));
        }
    }
    if (!(*ans)[level]) {
        (*ans)[level] = calloc(32, sizeof(int));
        (*returnColumnSizes)[level] = 0;
    }
    int n = (*returnColumnSizes)[level];
    if (n >= 32 && !(n & (n-1))) {
        n <<= 1;
        (*ans)[level] = realloc((*ans)[level], n*sizeof(int));
    }
    (*ans)[level][(*returnColumnSizes)[level]++] = curr->val;

}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 20;
    int** ans = calloc(*returnSize, sizeof(int*));
    int deepest = 0;
    memset(ans, NULL, (*returnSize)*sizeof(int*));
    *returnColumnSizes = calloc(*returnSize, sizeof(int));
    traverse(root, &ans, 0, &deepest, returnSize, returnColumnSizes);
    int new_size = (root) ? deepest+1 : 0;
    ans = realloc(ans, new_size*sizeof(int*));
    *returnColumnSizes = realloc(*returnColumnSizes, new_size*sizeof(int));
    for (int i = 0; i < new_size; i++) {
        ans[i] = realloc(ans[i], (*returnColumnSizes)[i]*sizeof(int));
    }
    *returnSize = new_size;
    return ans;
}
