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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        q.push(root);
        while (!q.empty()) {
            long long sum = 0;
            for (int i = 0, s = q.size(); i < s; ++i) {
                TreeNode* curr = q.front();
                sum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                q.pop();
            }
            if (pq.size() < k) {
                pq.push(sum);
            } else if (sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        }
        return (pq.size() == k) ? pq.top() : -1;
    }
};
