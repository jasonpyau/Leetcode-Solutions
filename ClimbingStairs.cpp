class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        while (n-- > 0) {
            int c = b;
            b = a + b;
            a = c;
        }
        return b;
    }
};
