class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1, l = 0, r = 0, ans = 0;
        while (r < nums.size()) {
            if (prod < k) {
                prod *= nums[r++];
            } else {
                prod = max(1, prod/nums[l++]);
                r += (l > r);
            }
            if (prod < k) {
                ans += r-l;
            }
        }
        if (prod < k) {
            return ans;
        }
        while (l < nums.size()) {
            prod /= nums[l++];
            if (prod < k) {
                ans += r-l;
                break;
            }
        }
        return ans;
    }
};
