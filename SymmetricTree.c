/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

bool traverse(TreeNode* left, TreeNode* right) {
    if (!left) {
        if (!right) {
            return true;
        }
        return false;
    } else if (!right) {
        return false;
    } else if (left->val != right->val) {
        return false;
    }
    return (traverse(left->left, right->right) && traverse(left->right, right->left));
}

bool isSymmetric(TreeNode* root) {
    return traverse(root, root);
}
