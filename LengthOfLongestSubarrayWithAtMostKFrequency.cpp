class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, l = 0, r = 0;
        bool bad = false;
        unordered_map<int, int> freq;
        while (r < nums.size()) {
            if (bad) {
                if (--freq[nums[l++]] == k) {
                    bad = false;
                }
            } else if (freq[nums[r++]]++ == k) {
                bad = true;
            } else {
                ans = max(ans, r-l);
            }
        }
        return ans;
    }
};
