class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0], newEnd = newInterval[1], i;
        vector<vector<int>> ans;
        for (i = 0; i < intervals.size(); ++i) {
            vector<int>& interval = intervals[i];
            if (interval[1] < newStart) {
                ans.push_back(interval);
            } else if (interval[0] > newEnd) {
                break;
            } else {
                newStart = min(newStart, interval[0]);
                newEnd = max(newEnd, interval[1]);
            }
        }
        ans.push_back({{newStart, newEnd}});
        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        return ans;   
    }
};
