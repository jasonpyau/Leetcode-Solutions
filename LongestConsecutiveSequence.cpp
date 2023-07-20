class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0, curr = 0;
        for (int num : set) {
            if (!set.count(num-1)) {
                curr = 1;
                while (set.count(++num)) {
                    ++curr;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
