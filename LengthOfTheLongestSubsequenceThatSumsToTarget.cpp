class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target+1, INIT);
        for (int i = 0; i < nums.size(); ++i) {
            // Impossible to ever take nums[i].
            if (nums[i] > target) {
                continue;
            }
            // Start j such that nums[i]+j <= target.
            for (int j = target-nums[i]; j > 0; --j) {
                // Needs to be possible to make a subsequence equal to nums[i]+j.
                if (dp[j] != INIT) {
                    int take = dp[j]+1;
                    dp[j+nums[i]] = max(dp[j+nums[i]], take);
                }
            }
            // Choose to take nums[i] as the start of the subsequence.
            dp[nums[i]] = max(dp[nums[i]], 1);
        }
        return dp[target];
    }
private:
    const int INIT = -1;
};
