class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        comb(candidates, 0, target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void comb(vector<int>& candidates, int i, int target) {
        if (target < 0) {
            return;
        } else if (!target) {
            ans.push_back(curr);
            return;
        }
        for (; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            comb(candidates, i, target-candidates[i]);
            curr.pop_back();
        }
    }
};
