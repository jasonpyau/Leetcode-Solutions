class Solution {
public:
    int findMaxK(vector<int>& nums) {
        bool nums_set[2001];
        memset(nums_set, 0, 2001*sizeof(bool));
        int ans = -1;
        for (int num : nums) {
            nums_set[num+1000] = true;
            if (nums_set[-num+1000])
                ans = max(ans, abs(num));
        }
        return ans;
    }
};
