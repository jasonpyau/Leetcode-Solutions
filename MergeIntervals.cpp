class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Solution::compareTo);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ) {
            vector<int>& start_interval = intervals[i];
            int start = start_interval[0], end = start_interval[1];
            while (++i < intervals.size()) {
                vector<int>& curr_interval = intervals[i];
                if (curr_interval[0] <= end) {
                    end = max(end, curr_interval[1]);
                } else {
                    break;
                }
            }
            vector<int> new_interval(2);
            new_interval[0] = start;
            new_interval[1] = end;
            ans.push_back(new_interval);
        }
        return ans;
    }
private:
    static bool compareTo(vector<int>& lhs, vector<int>& rhs) {
        return (rhs[0] > lhs[0]);
    }
};
