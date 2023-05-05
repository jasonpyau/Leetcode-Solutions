class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rowLen = grid.size(), colLen = grid[0].size();
        vis.resize(rowLen);
        for (vector<bool>& row : vis) {
            row.resize(colLen);
            fill(row.begin(), row.end(), false);
        }
        int ans = 0;
        for (int r = 0; r < rowLen; r++) {
            for (int c = 0; c < colLen; c++) {
                ans = max(ans, searchAns(r, c, grid));
            }
        }
        return ans;
    }
private:
    vector<vector<bool>> vis;
    int searchAns(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || vis[r][c] || !grid[r][c])
            return 0;
        vis[r][c] = true;
        return grid[r][c]+searchAns(r, c-1, grid)+searchAns(r, c+1, grid)+searchAns(r-1, c, grid)+searchAns(r+1, c, grid);
    }
};
