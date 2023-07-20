class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> num_to_freq;
        for (int num : nums) {
            ++num_to_freq[num];
        }
        vector<pair<int,int>> pairs;
        pairs.reserve(num_to_freq.size());
        for (auto it : num_to_freq) {
            pairs.push_back(make_pair(it.second, it.first));
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = pairs[i].second;
        }
        return ans;
    }
};
