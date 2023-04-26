class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans.reserve(nums1.size());
        vector<bool> n1_contains(1001, 0);
        for (int n1 : nums1)
            n1_contains[n1] = true;
        for (int n2 : nums2) {
            if (n1_contains[n2]) {
                n1_contains[n2] = false;
                ans.push_back(n2);
            }
        }
        return ans;
    }
};
