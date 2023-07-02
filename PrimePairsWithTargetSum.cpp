class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> primes(n+1, true);
        vector<vector<int>> ans;
        int sq = sqrt(n);
        for (int i = 2; i <= sq; i++) {
            if (primes[i]) {
                for (int j = i*2; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        for (int i = 2; i <= n>>1; i++) {
            if (primes[i] && primes[n-i]) {
                vector<int> curr(2);
                curr[0] = i;
                curr[1] = n-i;
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
