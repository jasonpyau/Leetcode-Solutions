class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n+1, INIT);
        memo[0] = 1;
        return solve(n, memo);
    }
private:
    const int INIT = -1;

    int solve(int n, vector<int>& memo) {
        if (memo[n] != INIT) {
            return memo[n];
        }
        int unique = 0;
        // Make left, right subtree of size l, r, respectively.
        for (int l = 0, r = n-1; l < n; ++l, --r) {
            unique += solve(l, memo)*solve(r, memo);
        }
        return memo[n] = unique;
    }
};
