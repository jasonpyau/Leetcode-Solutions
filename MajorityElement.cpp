class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!cnt) {
                ans = nums[i];
            }
            if (nums[i] == ans) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return ans;
    }
};
