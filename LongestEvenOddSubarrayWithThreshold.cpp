class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int curr, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i]&1 || nums[i] > threshold) {
                i++;
                if (i == nums.size()) {
                    return ans;
                }
            }
            curr = 1;
            while (i < nums.size()-1 && nums[i+1] <= threshold && (nums[i]^nums[i+1])&1) {
                curr++;
                i++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
