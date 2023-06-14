/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define min(a,b) (a > b) ? b : a

int ans, last_val;
void traverse(struct TreeNode* curr) {
    if (!curr) {
        return;
    }
    traverse(curr->left);
    ans = min(ans, abs(curr->val-last_val));
    last_val = curr->val;
    traverse(curr->right);
}

int getMinimumDifference(struct TreeNode* root) {
    ans = INT_MAX, last_val = INT_MAX;
    traverse(root);
    return ans;
}
