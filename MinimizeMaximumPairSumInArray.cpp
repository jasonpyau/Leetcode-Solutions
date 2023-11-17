class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int l = 0, r = nums.size()-1; r > l; ++l, --r) {
            ans = max(ans, nums[l]+nums[r]);
        }
        return ans;
    }
};
