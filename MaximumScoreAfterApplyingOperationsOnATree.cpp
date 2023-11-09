class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> adj(edges.size()+1);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long pick_all = 0;
        for (int value : values) {
            pick_all += value;
        }
        return pick_all-no_pick(0, -1, adj, values); 
    }
private:
    long long no_pick(int node, int parent, vector<vector<int>>& adj, vector<int>& values) {
        // Leaf node, but you can pick the root if it's the only node.
        if (adj[node].size() == 1 && node != 0) {
            return values[node];
        }
        long long no_pick_child = 0;
        for (int child : adj[node]) {
            if (child != parent) {
                no_pick_child += no_pick(child, node, adj, values);
            }
        }
        // Either don't pick the current node or all its children.
        return min(no_pick_child, 0ll+values[node]);
    }
};
