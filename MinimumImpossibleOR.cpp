class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int ors = 0;
        for (int num : nums) {
            // pow 2
            if (!(num & (num - 1))) {
                ors |= num;
            }
        }
        int ans = 1;
        while (ors & 1) {
            ors >>= 1;
            ans <<= 1;
        }
        return ans;
    }
};
