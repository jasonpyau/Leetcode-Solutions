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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root) {
            st.push(root);
        }
    }
    
    int next() {
        TreeNode* curr = st.top();
        if (checkLeft) {
            while (curr->left) {
                st.push(curr->left);
                curr = curr->left;
            }
        }
        st.pop();
        if (curr->right) {
            st.push(curr->right);
            checkLeft = true;
        } else {
            checkLeft = false;
        }
        return curr->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
private:
    stack<TreeNode*> st;
    bool checkLeft = true;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
