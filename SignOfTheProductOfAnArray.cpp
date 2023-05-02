class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negs = 0;
        for (int num : nums) {
            if (num <= 0) {
                if (!num)
                    return 0;
                negs++;
            }
        }
        return (negs & 1) ? -1 : 1;
    }
};
