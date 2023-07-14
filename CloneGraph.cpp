/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        vector<Node*> copied_nodes(101, NULL);
        copied_nodes[node->val] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        Node* curr;
        int neighbor_val;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            for (Node* neighbor : curr->neighbors) {
                neighbor_val = neighbor->val;
                if (!copied_nodes[neighbor_val]) {
                    copied_nodes[neighbor_val] = new Node(neighbor_val);
                    q.push(neighbor);
                }
                copied_nodes[curr->val]->neighbors.push_back(copied_nodes[neighbor_val]);
            }
        }
        return copied_nodes[1];
    }
};
