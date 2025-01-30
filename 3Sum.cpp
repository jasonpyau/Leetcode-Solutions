class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (flag && nums[i-1] == nums[i]) {
                continue;
            }
            flag = false;
            for (int l = i+1, r = n-1; r > l;) {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum > 0) {
                    --r;
                } else if (sum < 0) {
                    ++l;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (++l < n && nums[l-1] == nums[l]) {}
                    while (--r >= 0 && nums[r] == nums[r+1]) {}
                }
            }
            if (i+1 < n && nums[i] == nums[i+1]) {
                flag = true;
            }
        }
        return ans;
    }
};
