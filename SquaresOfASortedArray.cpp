class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l = 0, i = n-1, r = n-1;
        vector<int> ans(n);
        while (r >= l) {
            if (nums[r] >= abs(nums[l])) {
                ans[i--] = nums[r]*nums[r--];
            } else {
                ans[i--] = nums[l]*nums[l++];
            }
        }
        return ans;
    }
};
