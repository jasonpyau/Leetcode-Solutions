class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        // 1000... 0111... Disjoint!
        return !(n&(n-1));
    }
};
