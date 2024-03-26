class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int INF = nums.size()+1;
        // Dummy value. [1,2,3] -> need to be able to map 3!
        nums.push_back(INF);
        for (int& num : nums) {
            if (num < 0 || num >= nums.size()) {
                num = INF;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            int num = abs(nums[i]);
            if (num == INF) {
                continue;
            } else if (nums[num] == 0) {
                // Can't mark this negative.
                nums[num] = -INF;
            } else {
                nums[num] = min(nums[num], -nums[num]);
            }
        }
        int ans = INF;
        // No need to check if zero exists.
        for (int i = 1; i < nums.size(); ++i) {
            // We marked nums[i] as negative if i existed in nums.
            if (nums[i] >= 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
