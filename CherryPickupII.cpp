class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        memo = vector<vector<vector<int>>>(rows, vector<vector<int>>(cols, vector<int>(cols, INIT)));
        return solve(0, 0, cols-1, rows, cols, grid);
    }
private:
    const int NEG_INF = -1-100*70, INIT = -1;
    vector<vector<vector<int>>> memo;
    vector<int> dX = {-1, 0, 1};

    int solve(int r, int c1, int c2, int rows, int cols, vector<vector<int>>& grid) {
        if (c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols) {
            return NEG_INF;
        } else if (r == rows) {
            return 0;
        } else if (memo[r][c1][c2] != INIT) {
            return memo[r][c1][c2];
        }
        int take = ((c1 == c2) ? 0 : grid[r][c1])+grid[r][c2];
        int best = 0;
        for (int dC1 : dX) {
            for (int dC2 : dX) {
                best = max(best, solve(r+1, c1+dC1, c2+dC2, rows, cols, grid));
            }
        }
        return memo[r][c1][c2] = take+best;
    }
};
