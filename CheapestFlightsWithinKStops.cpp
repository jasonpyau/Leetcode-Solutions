class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Convert k into total visited cities.
        ++k;
        // first -> adjacent city.
        // second -> price.
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& f : flights) {
            adj[f[0]].push_back(make_pair(f[1], f[2]));
        }
        vector<vector<int>> dp(n, vector<int>(k+1, INF));
        // [0] -> price.
        // [1] -> k.
        // [2] -> city.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        dp[src][0] = 0;
        pq.push({0, 0, src});
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            int curr_price = curr[0], curr_k = curr[1], curr_city = curr[2];
            pq.pop();
            if (curr_k == k || curr_price > dp[curr_city][curr_k]) {
                continue;
            }
            for (pair<int, int>& flight : adj[curr_city]) {
                int next_price = curr_price+flight.second;
                int next_k = curr_k+1;
                int next_city = flight.first;
                if (next_price < dp[next_city][next_k]) {
                    dp[next_city][next_k] = next_price;
                    pq.push({next_price, next_k, next_city});
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[dst][i]);
        }
        return (ans == INF) ? -1 : ans;
    }
private:
    const int INF = 1e2*1e4+1;
};
