class Solution {
public:

    void traverse(int i, vector<vector<int>>& isConnected) {
        vis[i] = true;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && isConnected[i][j]) {
                traverse(j, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        n = isConnected.size();
        vis = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                traverse(i, isConnected);
                ans++;
            }
        }
        return ans;
    }
private:
    vector<bool> vis;
    int n;
};
