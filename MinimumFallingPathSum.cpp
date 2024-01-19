class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INF;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), INF));
        for (int c = 0; c < matrix[0].size(); ++c) {
            ans = min(ans, solve(0, c, memo, matrix));
        }
        return ans;
    }
private:

    const int INF = 2e4+2;

    int solve(int r, int c, vector<vector<int>>& memo, vector<vector<int>>& matrix) {
        if (r == matrix.size()) {
            return 0;
        } else if (c < 0 || c >= matrix[0].size()) {
            return INF;
        } else if (memo[r][c] != INF) {
            return memo[r][c];
        }
        return memo[r][c] = matrix[r][c]+min({solve(r+1, c-1, memo, matrix), solve(r+1, c, memo, matrix), solve(r+1, c+1, memo, matrix)});
    }
};
