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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> node_stack;
        int i = 0, prevDepth = 0;
        TreeNode* root = new TreeNode(getVal(traversal, i));
        node_stack.push(root);
        while (i < traversal.size()) {
            int depth = getDepth(traversal, i);
            TreeNode* node = new TreeNode(getVal(traversal, i));
            if (depth == prevDepth+1) {
                node_stack.top()->left = node;
            } else if (depth <= prevDepth) {
                int diff = prevDepth-depth;
                for (int i = 0; i <= diff; i++) {
                    node_stack.pop();
                }
                node_stack.top()->right = node;
            }
            prevDepth = depth;
            node_stack.push(node);
        }
        return root;
    }
private:
    int getDepth(string& traversal, int& i) {
        int depth = 0;
        while (traversal[i] == '-') {
            depth++;
            i++;
        }
        return depth;
    }
    int getVal(string& traversal, int& i) {
        int len = 0;
        while (traversal[i+len] != '-' && i+len < traversal.size()) {
            len++;
        }
        int val = stoi(traversal.substr(i, len));
        i += len;
        return val;
    }
};
