class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            int best = i-1;
            for (int j = 2, k = i>>1; j <= k; ++j) {
                best = max(best, max(dp[j], j)*max(dp[i-j], i-j));
            }
            dp[i] = best;
        }
        return dp[n];
    }
};
