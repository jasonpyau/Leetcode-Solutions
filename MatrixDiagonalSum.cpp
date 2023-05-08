class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int sideLen = mat.size();
        for (int r = 0, c = 0; r < sideLen; r++, c++)
            ans += mat[r][c];
        for (int r = sideLen-1, c = 0; r >= 0; r--, c++)
            ans += mat[r][c];
        if (sideLen & 1)
            ans -= mat[sideLen>>1][sideLen>>1];
        return ans;
    }
};
