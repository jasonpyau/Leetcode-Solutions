class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(21, false);
        perm(nums);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used;

    void perm(vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int num : nums) {
            if (!used[num+10]) {
                curr.push_back(num);
                used[num+10] = true;
                perm(nums);
                used[num+10] = false;
                curr.pop_back();
            }
        }
    }
};
