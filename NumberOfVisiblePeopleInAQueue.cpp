class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> inds;
        vector<int> ans(heights.size(), 0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!inds.empty() && heights[i] > heights[inds.top()]) {
                ++ans[inds.top()];
                inds.pop();
            }
            if (!inds.empty()) {
                ++ans[inds.top()];
            }
            inds.push(i);
        }
        return ans;
    }
};
