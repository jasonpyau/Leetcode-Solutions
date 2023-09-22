class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, INF);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i-coin < 0) {
                    break;
                }
                dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        return (dp[amount] != INF) ? dp[amount] : -1;
    }
private:
    const int INF = 1e4+1;
};
