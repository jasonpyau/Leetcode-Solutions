class Solution {
public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), INIT);
        return rob(nums, 0);
    }
private:
    const int INIT = -1;
    vector<int> memo;

    int rob(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        } else if (memo[i] != INIT) {
            return memo[i];
        }
        memo[i] = max(rob(nums, i+1), nums[i]+rob(nums, i+2));
        return memo[i];
    }
};
