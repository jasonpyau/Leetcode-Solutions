class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        // Current day.
        for (int i = 1; i <= n; ++i) {
            // Number of absent days.
            for (int j = 0; j < 2; ++j) {
                // Number of consecutive late days.
                for (int k = 0; k < 3; ++k) {
                    // Count ways if student was present on day i.
                    add(dp[i][j][0], dp[i-1][j][k]);
                    // Count ways if student was absent on day i.
                    if (j < 1) {
                        add(dp[i][j+1][0], dp[i-1][j][k]);
                    }
                    // Count ways if student is late on day i.
                    if (k < 2) {
                        add(dp[i][j][k+1], dp[i-1][j][k]);
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                add(ans, dp[n][j][k]);
            }
        }
        return ans;
    }
private:
    const int MOD = 1e9+7;

    void add(int& a, int b) {
        a += b;
        if (a >= MOD) {
            a -= MOD;
        }
    }
};
