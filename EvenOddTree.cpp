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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        for (int level = 0; !q.empty(); ++level) {
            int size = q.size(), last = (level&1) ? POS_INF : NEG_INF;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr_node = q.front();
                int curr = curr_node->val;
                q.pop();
                if ((0ll+curr+level)%2 == 0) {
                    // Must be even level odd value, odd level even value.
                    // 1e6+1e5 -> long!
                    return false;
                } else if (level%2 && curr >= last) {
                    // Odd level, decreasing order.
                    return false;
                } else if (level%2 == 0 && last >= curr) {
                    // Even level, increasing order.
                    return false;
                }
                last = curr;
                if (curr_node->left) {
                    q.push(curr_node->left);
                }
                if (curr_node->right) {
                    q.push(curr_node->right);
                }
            }
        }
        return true;
    }
private:
    const int POS_INF = 1e6+1, NEG_INF = -1;
};
