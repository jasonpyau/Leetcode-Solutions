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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> last_nodes(1, root);
        for (int i = 1; ; i++) {
            vector<TreeNode*> curr_nodes;
            curr_nodes.reserve(last_nodes.size()*2);
            if (!last_nodes[0]->left)
                break;
            for (TreeNode* node : last_nodes) {
                curr_nodes.push_back(node->left);
                curr_nodes.push_back(node->right);
            }
            if (i & 1) {
                for (int l = 0, r = curr_nodes.size()-1; r > l; l++, r--) {
                    swap(curr_nodes[l]->val, curr_nodes[r]->val);
                }
            }
            last_nodes = curr_nodes;
        }
        return root;
    }
};
