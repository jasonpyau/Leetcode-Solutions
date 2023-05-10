class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int digs1 = 0, digs2 = 0;
        for (int dig : nums1)
            digs1 |= 1<<dig;
        for (int dig : nums2)
            digs2 |= 1<<dig;
        int similar = digs1&digs2;
        if (similar)
            return getRightMostBit(similar);
        int dig1 = getRightMostBit(digs1);
        int dig2 = getRightMostBit(digs2);
        if (dig1 > dig2)
            swap(dig1, dig2);
        return dig1*10+dig2;
    }
private:
    int getRightMostBit(int n) {
        int res = 0;
        while (!(n&1))
            res++, n >>= 1;
        return res;
    }
};
