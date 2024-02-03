class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Recursive solution, for each i, make k more recursive calls and memoize.
        // Iterative: for each i, take the best from i-j for j in [1,k] and i+1 >= j.
        vector<int> dp(k+1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 1, curr_max = 0; j <= k && i+1 >= j; ++j) {
                curr_max = max(curr_max, arr[i+1-j]);
                dp[0] = max(dp[0], dp[j]+j*curr_max);
            }
            for (int j = k; j > 0; --j) {
                dp[j] = dp[j-1];
            }
        }
        return dp[1];
    }
};
