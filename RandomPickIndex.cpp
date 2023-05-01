class Solution {
public:
    Solution(vector<int>& nums) {
        srand(time(NULL));
        for (int i = 0; i < nums.size(); i++)
            choose[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        vector<int>& nums = choose[target];
        return nums[rand()%nums.size()];
    }
private:
    map<int,vector<int>> choose;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
