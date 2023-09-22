class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        memo = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INF));
        return dfs(0, 0, grid);
    }
private:
    vector<vector<int>> memo;
    const int INF = 200*200*200;
    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size()) {
            return INF;
        } else if (c < 0 || c >= grid[0].size()) {
            return INF;
        } else if (memo[r][c] != INF) {
            return memo[r][c];
        } else if (r == grid.size()-1 && c == grid[0].size()-1) {
            return grid[r][c];
        }
        int right = grid[r][c]+dfs(r, c+1, grid);
        int down = grid[r][c]+dfs(r+1, c, grid);
        memo[r][c] = min(right, down);
        return memo[r][c];
    }
};
