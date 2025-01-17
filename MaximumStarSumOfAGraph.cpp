class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if (k == 0) {
            return *max_element(vals.begin(), vals.end());
        }
        vector<vector<int>> adj(vals.size());
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(vals.size(), false);
        int ans = INT_MIN;
        for (int u = 0; u < vals.size(); ++u) {
            if (!vis[u]) {
                ans = max(ans, find_max_star(u, adj, vals, vis, k));
            }
        }
        return ans;
    }
private:
    int find_max_star(int u, vector<vector<int>>& adj, vector<int>& vals, vector<bool>& vis, int k) {
        int max_star = INT_MIN;
        priority_queue<int, vector<int>, greater<int>> pq;
        vis[u] = true;
        for (int v : adj[u]) {
            if (pq.size() < k) {
                pq.push(vals[v]);
            } else if (pq.top() < vals[v]) {
                pq.pop();
                pq.push(vals[v]);
            }
            if (!vis[v]) {
                max_star = max(max_star, find_max_star(v, adj, vals, vis, k));
            }
        }
        int sum = vals[u];
        while (!pq.empty()) {
            if (pq.top() > 0) {
                sum += pq.top();
            }
            pq.pop();
        }
        return max_star = max(max_star, sum);
    }
};
