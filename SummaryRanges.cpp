class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }
        int l, r;
        for (l = 0, r = 1; r < nums.size(); r++) {
            if (r-l != 0L+nums[r]-nums[l]) {
                ans.push_back(createRange(nums[l], nums[r-1]));
                l = r;
            }
        }
        ans.push_back(createRange(nums[l], nums[r-1]));
        return ans;
    }
private:
    string createRange(int a, int b) {
        if (a == b) {
            return to_string(a);
        } else {
            return to_string(a)+"->"+to_string(b);
        }
    }
};
