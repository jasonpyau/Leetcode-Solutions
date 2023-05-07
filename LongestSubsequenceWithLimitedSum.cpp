class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> sums(len);
        sums[0] = nums[0];
        for (int i = 1; i < len; i++)
            sums[i] = sums[i-1]+nums[i];
        vector<int> ans;
        ans.reserve(queries.size());
        for (int query : queries) {
            int l = 0, r = len-1, q_ans = 0;
            while (r >= l) {
                int m = (l+r)>>1;
                if (sums[m] == query) {
                    q_ans = m+1;
                    break;
                } else if (sums[m] < query) {
                    l = m+1;
                    q_ans = m+1;
                } else {
                    r = m-1;
                }
            }
            ans.push_back(q_ans);
        }
        return ans;
    }
};
