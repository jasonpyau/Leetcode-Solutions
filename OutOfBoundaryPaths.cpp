class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove+1, INIT)));
        return solve(startRow, startColumn, maxMove, memo);
    }
private:
    const int INIT = -1, MOD = 1e9+7;
    vector<int> dX = {1,0,-1,0}, dY = {0,1,0,-1};

    int solve(int r, int c, int moves, vector<vector<vector<int>>>& memo) {
        if (r == -1 || c == -1 || r == memo.size() || c == memo[0].size()) {
            return 1;
        } else if (!moves) {
            return 0;
        } else if (memo[r][c][moves] != INIT) {
            return memo[r][c][moves];
        }
        int res = 0;
        for (int i = 0; i < dX.size(); ++i) {
            res = (res+solve(r+dY[i], c+dX[i], moves-1, memo))%MOD;
        }
        return memo[r][c][moves] = res;
    }
};
