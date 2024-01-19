class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        // 2^20 > 10^6.
        int ans = 0;
        for (int i = 0; i < 20; ++i) {
            if ((k>>i&1) != (x>>i&1)) {
                ++ans;
            }
        }
        return ans;
    }
};
