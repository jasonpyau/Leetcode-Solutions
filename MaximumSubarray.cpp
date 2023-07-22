class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0], ans = curr;
        for (int i = 1, num; i < nums.size(); i++) {
            num = nums[i];
            if (num > curr && curr < 0) {
                curr = num;
            } else {
                curr += num;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
