/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

bool hasPathSum(TreeNode* curr, int targetSum) {
    if (!curr) {
        return false;
    }
    targetSum -= curr->val;
    if (!targetSum && !curr->left && !curr->right) {
        return true;
    }
    return (hasPathSum(curr->left, targetSum) || hasPathSum(curr->right, targetSum));
}
