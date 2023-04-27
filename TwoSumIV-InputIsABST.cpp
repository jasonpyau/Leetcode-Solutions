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
    bool findTarget(TreeNode* root, int k) {
        return traverse(root, k);
    }
private:
    unordered_set<int> visited;
    bool traverse(TreeNode* curr, int k) {
        if (!curr)
            return false;
        if (visited.find(k-curr->val) != visited.end()) {
            return true;
        }
        visited.insert(curr->val);
        return traverse(curr->left, k) || traverse(curr->right, k);
    }
};
