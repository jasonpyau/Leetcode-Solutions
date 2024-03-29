class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int max_val = *max_element(nums.begin(), nums.end());
        for (int l = 0, r = 0, cnt = 0, last_l = -1; r < nums.size(); ++r) {
            if (nums[r] == max_val) {
                if (++cnt == k) {
                    // We force the window to have k max_vals!
                    while (nums[l] != max_val) {
                        ++l;
                    }
                    // It has k max_vals, we don't care about anything else.
                    // Don't double count, use last_l.
                    ans += 1ll*(l-last_l)*(nums.size()-r);
                    last_l = l, ++l, --cnt;
                }
            }
        }
        return ans;
    }
};
