class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 1, i = 0, size = nums.size();
        for (; i < size && max_jump; i++)
            max_jump = max(--max_jump, nums[i]);
        return i == size;
    }
};
