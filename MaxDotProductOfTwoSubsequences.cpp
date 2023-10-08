class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            swap(nums1, nums2);
        }
        vector<vector<int>> dp(2, vector<int>(nums2.size()+1, INIT));
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                int take = nums1[i]*nums2[j-1]+max(0, dp[0][j-1]), notake = max(dp[1][j-1], dp[0][j]);
                dp[1][j] = max(take, notake);
            }
            swap(dp[0], dp[1]);
        }
        return dp[0].back();
    }
private:
    const int INIT = -2e3-1;
};
