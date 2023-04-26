/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traverse(struct TreeNode* curr, int l, int h) {
    if (!curr) {
        return 0;
    }
    if (curr->val < l) {
        return traverse(curr->right, l, h);
    } else if (curr->val > h) {
        return traverse(curr->left, l, h);
    }
    return curr->val + traverse(curr->left, l, h) + traverse(curr->right, l, h);
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    int ans = traverse(root, low, high);
    return ans;
}
