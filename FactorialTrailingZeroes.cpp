class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n > 1)
            ans += (n /= 5);
        return ans;
    }
};
