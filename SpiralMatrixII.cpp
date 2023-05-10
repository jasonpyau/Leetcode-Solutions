class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vis.resize(n);
        for (vector<bool>& row : vis) {
            row.resize(n);
            fill(row.begin(), row.end(), false);
        }
        vector<vector<int>> ans(n);
        for (vector<int>& row : ans) {
            row.resize(n);
        }
        generate(0, 0, 0, 0, ans);
        return ans;
    }
private:
    vector<vector<bool>> vis;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    void generate(int r, int c, int d, int val, vector<vector<int>>& ans) {
        if (r < 0 || r >= ans.size() || c < 0 || c >= ans[0].size() || vis[r][c]) {
            return;
        }
        ans[r][c] = ++val;
        vis[r][c] = true;
        generate(r+dir[d][0], c+dir[d][1], d, val, ans);
        d++, d %= 4;
        generate(r+dir[d][0], c+dir[d][1], d, val, ans);
    }
};
