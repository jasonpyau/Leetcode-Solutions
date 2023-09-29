class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums[nums.size()-1] >= nums[0]) {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i-1] > nums[i]) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i-1] < nums[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
