class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size(), k;
        sort(nums.begin(), nums.end());
        vector<long long> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i-1]+nums[i];
        }
        for (k = n-1; k >= 2; --k) {
            if (prefix_sum[k]-nums[k] > nums[k]) {
                // Sum of all k-1 smallest > nums[k]!
                break;
            }
        }
        // If k = 2, 0-indexed, was valid, it would've hit break and not decrement.
        return (k == 1) ? -1 : prefix_sum[k];
    }
};
