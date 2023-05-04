class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = 0;
        for (int num : nums)
            max = std::max(max, num);
        return (k*(max+max+k-1))>>1;
    }
};
