/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(struct TreeNode* root, int* ans) {
    if (!root) {
        return 0;
    }
    int left = solve(root->left, ans);
    int right = solve(root->right, ans);
    *ans = max(*ans, left+right);
    return 1+max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    solve(root, &ans);
    return ans;
}
