class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        get_subsets(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void get_subsets(vector<int>& nums, int k) {
        ans.push_back(curr);
        if (k == nums.size()) {
            return;
        }
        for (int i = k; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            get_subsets(nums, i+1);
            curr.pop_back();
        }
    }
};
