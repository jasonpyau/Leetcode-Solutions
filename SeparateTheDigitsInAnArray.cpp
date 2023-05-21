class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            vector<int> curr;
            while (num) {
                curr.push_back(num%10);
                num /= 10;
            }
            for (int i = curr.size()-1; i >= 0; i--)
                ans.push_back(curr[i]);
        }
        return ans;
    }
};
