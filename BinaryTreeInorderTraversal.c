/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode* curr, int* ans, int* num_nodes) {
    if (!curr) {
        return;
    }
    traverse(curr->left, ans, num_nodes);
    ans[(*num_nodes)++] = curr->val;
    traverse(curr->right, ans, num_nodes);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ans = calloc(100, sizeof(int));
    *returnSize = 0;
    traverse(root, ans, returnSize);
    ans = realloc(ans, (*returnSize)*sizeof(int));
    return ans;
}
