class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sq = sqrt(n);
        int ans = 0, div;
        for (int i = 1; i <= sq; i++) {
            if (n%i == 0) {
                ans += square(nums[i-1]);
                if ((div = n/i) != i) {
                    ans += square(nums[div-1]);
                }
            }
        }
        return ans;
    }
private:
    inline int square(int num) {
        return num*num;
    }
};
