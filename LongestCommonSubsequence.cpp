class Solution {
public:
    // Lightly modified from geeksforgeeks.
    int longestCommonSubsequence(string text1, string text2) {
        if (text2.size() > text1.size()) {
            swap(text1, text2);
        }
        int t1_len = text1.size(), t2_len = text2.size();
        vector<vector<int>> dp(2, vector<int>(t2_len+1, 0));
        for (int i = 1; i <= t1_len; ++i) {
            for (int j = 1; j <= t2_len; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[1][j] = dp[0][j-1]+1;
                } else {
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }
            }
            swap(dp[0], dp[1]);
        }
        return dp[0][t2_len];
    }
};
