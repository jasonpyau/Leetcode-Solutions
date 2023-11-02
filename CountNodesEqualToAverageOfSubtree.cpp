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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(ans, root);
        return ans;
    }
private:
    pair<int, int> solve(int& ans, TreeNode* root) {
        if (!root) {
            return make_pair(0, 0);
        }
        pair<int, int> left = solve(ans, root->left), right = solve(ans, root->right);
        pair<int, int> res = make_pair(left.first+right.first+root->val, left.second+right.second+1);
        if (res.first/res.second == root->val) {
            ++ans;
        }
        return res;
    }
};
