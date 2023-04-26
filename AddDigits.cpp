class Solution {
public:
    int addDigits(int num) {
        if (!num)
            return 0;
        int ans = num%9;
        return (ans) ? ans : 9;
    }
};
