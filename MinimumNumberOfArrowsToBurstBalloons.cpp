class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return (a[1] < b[1]);
        });
        int ans = 1, arrow = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > arrow) {
                ++ans;
                arrow = points[i][1];
            }
        }
        return ans;
    }
};
