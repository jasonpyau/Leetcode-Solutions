class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), INIT));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
private:
    const int NUMDIR = 4, INIT = -1;
    vector<int> dX = {0, 1, 0, -1};
    vector<int> dY = {1, 0, -1, 0};
    vector<vector<int>> memo;
    
    inline bool inbounds(int r, int c, vector<vector<int>>& matrix) {
        return (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size());
    }

    int dfs(int r, int c, vector<vector<int>>& matrix) {
        if (memo[r][c] != INIT) {
            return memo[r][c];
        }
        memo[r][c] = 0;
        int best = 0;
        for (int i = 0; i < NUMDIR; ++i) {
            int n_r = r+dY[i], n_c = c+dX[i];
            if (!inbounds(n_r, n_c, matrix) || matrix[r][c] >= matrix[n_r][n_c]) {
                continue;
            }
            best = max(best, dfs(n_r, n_c, matrix));
        }
        return memo[r][c] = 1+best;
    }
};
