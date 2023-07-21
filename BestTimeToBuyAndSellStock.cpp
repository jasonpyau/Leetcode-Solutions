class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], ans = 0;
        for (int price : prices) {
            ans = max(ans, price-buy);
            buy = min(buy, price);
        }
        return ans;
    }
};
