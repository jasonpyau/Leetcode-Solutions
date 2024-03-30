class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k)-atMostKDistinct(nums, k-1);
    }
private:
    int atMostKDistinct(vector<int>& nums, int k) {
        vector<int> freq(nums.size()+1, 0);
        int ans = 0;
        for (int l = 0, r = 0, cnt = 0; r < nums.size(); ++r) {
            cnt += (++freq[nums[r]] == 1);
            while (cnt > k) {
                cnt -= (--freq[nums[l++]] == 0);
            }
            ans += r-l+1;
        }
        return ans;
    }
};
