class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses), ans;
        vector<vector<int>> adj(numCourses);
        for (vector<int>& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            ++in_degree[prerequisite[0]];
        }
        ans.reserve(numCourses);
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree[i]) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                // No more prerequisites for this class.
                if (!--in_degree[next]) {
                    q.push(next);
                    ans.push_back(next);
                }
            }
        }
        if (ans.size() != numCourses) {
            ans.clear();
        }
        return ans;
    }
};
