class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // first -> person y.
        // second -> meeting time.
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& m : meetings) {
            adj[m[0]].push_back(make_pair(m[1], m[2]));
            adj[m[1]].push_back(make_pair(m[0], m[2]));
        }
        // First time each person knew of secret.
        vector<int> dp(n, INF);
        // first -> when person knew of secret.
        // second -> person x.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        pq.push(make_pair(0, firstPerson));
        dp[0] = 0;
        dp[firstPerson] = 0;
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            int curr_time = curr.first, x = curr.second;
            pq.pop();
            if (curr_time > dp[x]) {
                continue;
            }
            for (pair<int, int>& next : adj[x]) {
                int y = next.first, next_time = next.second;
                if (next_time >= curr_time && dp[y] > next_time) {
                    dp[y] = next_time;
                    pq.push(make_pair(next_time, y));
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (dp[i] != INF) {
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    const int INF = 1e5+1;
};
