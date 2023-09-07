/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

int sumOfLeftLeaves(TreeNode* curr) {
    if (!curr) {
        return 0;
    }
    TreeNode* left = curr->left;
    if (left && !(left->left || left->right)) {
        return left->val+sumOfLeftLeaves(curr->right);
    }
    return sumOfLeftLeaves(left)+sumOfLeftLeaves(curr->right);
}
