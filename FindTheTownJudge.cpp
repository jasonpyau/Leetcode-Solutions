class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted_by(n+1, 0), trusts(n+1, 0);
        for (vector<int>& t : trust) {
            ++trusted_by[t[1]];
            ++trusts[t[0]];
        }
        int ans = -1;
        for (int i = 1; i <= n; ++i) {
            if (trusted_by[i] == n-1 && !trusts[i]) {
                if (ans == -1) {
                    ans = i;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};
