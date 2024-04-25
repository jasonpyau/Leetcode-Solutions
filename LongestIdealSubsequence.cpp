class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        for (char ch : s) {
            int val = ch-'a';
            for (int i = max(val-k, 0); i < min(val+k+1, 26); ++i) {
                dp[val] = max(dp[val], dp[i]);
            }
            ++dp[val];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
