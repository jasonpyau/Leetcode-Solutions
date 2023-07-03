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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* curr = root;
        TreeNode* next = NULL;
        stack<TreeNode*> st;
        while (1) {
            if (curr->left) {
                if (curr->right) {
                    st.push(curr->right);
                }
                curr->right = curr->left;
                next = curr->left;
                curr->left = NULL;
            } else if (curr->right) {
                next = curr->right;
            } else {
                if (!st.size()) {
                    break;
                }
                curr->right = st.top();
                next = st.top();
                st.pop();
            }
            curr = next;
        }
    }
};
