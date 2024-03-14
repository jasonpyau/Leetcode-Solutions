class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        if (goal == 0) {
            for (int i = 0, streak = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    ++streak;
                } else {
                    streak = 0;
                }
                ans += streak;
            }
        } else {
            // Hold at most goal ints. I don't like the two-pointer I thought of.
            queue<int> q;
            for (int i = 0, streak = 0; i < nums.size(); ++i) {
                if (nums[i] == 1) {
                    if (q.size() == goal) {
                        q.pop();
                    }
                    q.push(streak+1);
                    streak = 0;
                } else {
                    ++streak;
                }
                if (q.size() == goal) {
                    ans += q.front();
                }
            }
        }
        return ans;
    }
};
