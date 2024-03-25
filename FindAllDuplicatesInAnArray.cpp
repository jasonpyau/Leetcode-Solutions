class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            int x = abs(num);
            if (nums[x-1] < 0) {
                ans.push_back(x);
            } else {
                nums[x-1] = -nums[x-1];
            }
        }
        return ans;
    }
};
