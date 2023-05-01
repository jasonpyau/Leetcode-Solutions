class Solution {
public:
    double average(vector<int>& salary) {
        int ans = 0;
        int min = INT_MAX, max = 0;
        for (int s : salary) {
            ans += s;
            min = std::min(min, s);
            max = std::max(max, s);
        }
        return (ans-min-max)/(salary.size()-2.0);
    }
};
