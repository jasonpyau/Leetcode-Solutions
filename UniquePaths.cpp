class Solution {
public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        memo[m-1][n-1] = 1;
        return dfs(0, 0);
    }
private:
    vector<vector<int>> memo;

    int dfs(int r, int c) {
        if (r >= memo.size()) {
            return 0;
        } else if (c >= memo[0].size()) {
            return 0;
        } else if (memo[r][c]) {
            return memo[r][c];
        }
        memo[r][c] = dfs(r, c+1)+dfs(r+1, c);
        return memo[r][c];
    }
};
