class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // A number xored by itself is zero!
        int mask = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            mask ^= i;
        }
        for (int num : nums) {
            mask ^= num;
        }
        return mask;
    }
};
