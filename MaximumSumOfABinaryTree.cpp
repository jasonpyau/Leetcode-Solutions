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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> level_nodes;
        level_nodes.push(root);
        int ans = 0, max_sum = INT_MIN;
        for (int level = 1; !level_nodes.empty(); level++) {
            int len = level_nodes.size(), curr_sum = 0;
            for (int i = 0; i < len; i++) {
                TreeNode* curr = level_nodes.front();
                level_nodes.pop();
                curr_sum += curr->val;
                if (curr->left) {
                    level_nodes.push(curr->left);
                }
                if (curr->right) {
                    level_nodes.push(curr->right);
                }
            }
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                ans = level;
            }
        }
        return ans;
    }
};
