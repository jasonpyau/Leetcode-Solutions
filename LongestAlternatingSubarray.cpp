class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1, i = 1, s_0, s_1;
        while (i < nums.size()) {
            while (i < nums.size()) {
                if (nums[i-1]+1 == nums[i]) {
                    s_0 = nums[i-1]+1;
                    s_1 = nums[i];
                    break;
                } else {
                    i++;
                }
            }
            for (int j = 0, curr = 1; i < nums.size(); i++, j++) {
                if (!(j&1) && nums[i-1]+1 != nums[i]) {
                    break;
                } else if (j&1 && nums[i-1] != nums[i]+1) {
                    break;
                }
                ans = max(ans, ++curr);
            }
        }
        return ans;
    }
};
