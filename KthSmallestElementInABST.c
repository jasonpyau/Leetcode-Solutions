/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void solve(struct TreeNode* root, int* k, int* ans) {
    if (!root) {
        return;
    }
    solve(root->left, k, ans);
    if (!--(*k)) {
        *ans = root->val;
        return;
    }
    solve(root->right, k, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans;
    solve(root, &k, &ans);
    return ans;
}
