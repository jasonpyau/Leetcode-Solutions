class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(2, vector<int>(5, 1));
        for (int i = 1; i < n; ++i) {
            fill(dp[1].begin(), dp[1].end(), 0);
            // Condition 1.
            dp[1][1] = dp[0][0];
            // Condition 2.
            dp[1][0] = dp[1][2] = dp[0][1];
            // Condition 3.
            dp[1][3] = dp[1][4] = dp[0][2];
            dp[1][0] = (dp[1][0]+dp[0][2])%MOD;
            dp[1][1] = (dp[1][1]+dp[0][2])%MOD;
            // Condition 4.
            dp[1][2] = (dp[1][2]+dp[0][3])%MOD;
            dp[1][4] = (dp[1][4]+dp[0][3])%MOD;
            // Condition 5.
            dp[1][0] = (dp[1][0]+dp[0][4])%MOD;
            swap(dp[0], dp[1]);
        }
        int ans = 0;
        for (int i = 0; i < dp[0].size(); ++i) {
            ans = (ans+dp[0][i])%MOD;
        }
        return ans;
    }
private:
    const int MOD = 1e9+7;
};
