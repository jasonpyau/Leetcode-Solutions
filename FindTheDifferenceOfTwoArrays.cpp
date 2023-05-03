class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        for (int num : nums1)
            set1.insert(num);
        for (int num : nums2)
            set2.insert(num);
        vector<vector<int>> ans(2);
        vector<int> ans1;
        ans1.reserve(set1.size());
        for (int num : set1)
            if (set2.find(num) == set2.end())
                ans1.push_back(num);
        vector<int> ans2;
        ans2.reserve(set2.size());
        for (int num : set2)
            if (set1.find(num) == set1.end())
                ans2.push_back(num);
        ans[0] = ans1;
        ans[1] = ans2;
        return ans;
    }
};
