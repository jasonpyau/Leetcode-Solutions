class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        bool pos = 1, neg = 1;
        for (int i = 1, diff; i < nums.size(); ++i) {
            diff = nums[i]-nums[i-1];
            if (diff > 0) {
                ans += neg;
                pos = true;
                neg = false;
            } else if (diff < 0) {
                ans += pos;
                pos = false;
                neg = true;
            }
        }
        return ans;
    }
};
