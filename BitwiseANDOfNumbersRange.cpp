class Solution {
public:
    // Observation 1: We know right has a bit on at or before left.
    // Observation 2: If right has a bit before left, the answer must be zero.
    // Then, from here similar idea. We can't do better if we have 101... and 110...
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 30; i >= 0; --i) {
            if ((left>>i)^(right>>i)) {
                break;
            }
            ans += (left&right&(1<<i));
        }
        return ans;
    }
};
