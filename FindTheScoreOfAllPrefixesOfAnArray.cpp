#define ll long long
class Solution {
public:
    vector<ll> findPrefixScore(vector<int>& nums) {
        int max = 0;
        ll sum = 0;
        vector<ll> ans;
        ans.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            max = std::max(max, nums[i]);
            sum += max + nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
