class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (vector<int>& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            ++in_degree[prerequisite[0]];
        }
        queue<int> q;
        int classes_taken = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree[i]) {
                q.push(i);
                ++classes_taken;
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                // No more prerequisites for this class.
                if (!--in_degree[next]) {
                    q.push(next);
                    ++classes_taken;
                }
            }
        }
        return (classes_taken == numCourses);
    }
};
