class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int min_k_i = -1, max_k_i = -1, bad_i = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == minK) {
                min_k_i = i;
            }
            if (nums[i] == maxK) {
                max_k_i = i;
            }
            if (nums[i] > maxK || nums[i] < minK) {
                bad_i = i;
            }
            // Start at (bad_i, min(min_k_i, max_k_i)], end at i.
            ans += max(0, min(min_k_i, max_k_i)-bad_i);
        }
        return ans;
    }
};
