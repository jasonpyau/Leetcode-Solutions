/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverse(struct TreeNode* curr, int num, int* ans) {
    if (curr == NULL) {
        return;
    }
    num = num*10+curr->val;
    if (!curr->left && !curr->right) {
        (*ans) += num;
        return;
    }
    traverse(curr->left, num, ans);
    traverse(curr->right, num, ans);
}

int sumNumbers(struct TreeNode* root) {
    int ans = 0;
    traverse(root, 0, &ans);
    return ans;
}
