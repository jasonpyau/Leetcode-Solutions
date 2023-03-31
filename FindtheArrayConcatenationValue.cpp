#define ll long long
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        ll ans = 0;
        for (int i = 0; i < (nums.size()+1)/2; i++) {
            int i2 = nums.size()-i-1;
            if (i == i2) {
                ans += nums[i];
            } else {
                ll p = (ll)pow(10, (ll)log10(nums[i2])+1);
                ans += nums[i]*p+nums[i2];
            }
        }
        return ans;
    }
};
