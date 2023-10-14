class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memo = vector<vector<int>>(time.size(), vector<int>(time.size()+1, 0));
        return solve(0, time.size(), cost, time);
    }
private:
    vector<vector<int>> memo;
    const int IMPOSSIBLE = 1e6*500+1;

    int solve(int i, int walls_needed, vector<int>& cost, vector<int>& time) {
        if (walls_needed <= 0) {
            return 0;
        } else if (i == time.size()) {
            return IMPOSSIBLE;
        } else if (memo[i][walls_needed]) {
            return memo[i][walls_needed];
        }
        int notake = solve(i+1, walls_needed, cost, time);
        int take = cost[i]+solve(i+1, walls_needed-1-time[i], cost, time);
        return memo[i][walls_needed] = min(notake, take);
    }
};
