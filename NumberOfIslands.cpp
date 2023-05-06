class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowLen = grid.size(), colLen = grid[0].size();
        vis.resize(rowLen);
        for (vector<bool>& row : vis) {
            row.resize(colLen);
            fill(row.begin(), row.end(), false);
        }
        int ans = 0;
        for (int r = 0; r < rowLen; r++) {
            for (int c = 0; c < colLen; c++) {
                ans += search(r, c, grid);
            }
        }
        return ans;
    }
private:
    vector<vector<bool>> vis;
    int search(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || vis[r][c] || grid[r][c] == '0')
            return 0;
        vis[r][c] = true;
        search(r, c-1, grid);
        search(r, c+1, grid);
        search(r-1, c, grid);
        search(r+1, c, grid);
        return 1;
    }
};
