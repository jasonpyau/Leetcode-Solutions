/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = NEG_INF;
        solve(root, ans);
        return ans;
    }
private:
    const int NEG_INF = -4e7;

    int solve(TreeNode* root, int& ans) {
        if (!root) {
            return NEG_INF;
        }
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        // Take root and best path from the children, or make the end of the path root.
        int best_continue = root->val+max({left, right, 0});
        // Can also connect the best paths from the two children.
        ans = max({ans, best_continue, root->val+left+right});
        // Can only continue paths root to descendent or just root.
        return best_continue;
    }
};
