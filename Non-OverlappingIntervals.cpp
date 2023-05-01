class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Solution::compareInterval);
        int ans = 0, end = INT_MIN;
        for (vector<int>& interval : intervals) {
            if (end > interval[0])
                ans++;
            else
                end = interval[1];
        }
        return ans;
    }
private:
    static bool compareInterval(vector<int>& lhs, vector<int>& rhs) {
        return (rhs[1] > lhs[1]);
    }
};
