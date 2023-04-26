/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int ans, deepest;
void traverse(struct TreeNode* curr, int depth) {
    if (curr == NULL) {
        return;
    } else if (depth > deepest) {
        ans = curr->val;
        deepest = depth;
    } else if (depth == deepest) {
        ans += curr->val;
    }
    traverse(curr->left, depth+1);
    traverse(curr->right, depth+1);
}

int deepestLeavesSum(struct TreeNode* root) {
    ans = 0, deepest = 0;
    traverse(root, 0);
    return ans;
}
