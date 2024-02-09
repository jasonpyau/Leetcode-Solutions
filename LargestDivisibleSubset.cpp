class Solution {
public:
    // O(n^2).
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        memo = vector<int>(nums.size(), 0);
        next = vector<int>(nums.size(), nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            solve(i, nums);
        }
        vector<int> ans;
        ans.reserve(best);
        for (int i = best_start; i < nums.size(); i = next[i]) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
private:
    int best_start, best;
    vector<int> memo, next;

    int solve(int k, vector<int>& nums) {
        if (k == nums.size()) {
            return 0;
        } else if (memo[k]) {
            return memo[k];
        }
        int curr_best = 1;
        for (int i = k+1; i < nums.size(); ++i) {
            if (nums[i]%nums[k] == 0) {
                int take = 1+solve(i, nums);
                if (take > curr_best) {
                    curr_best = take;
                    next[k] = i;
                }
            }
        }
        if (curr_best > best) {
            best_start = k;
            best = curr_best;
        }
        return memo[k] = curr_best;
    }
};
