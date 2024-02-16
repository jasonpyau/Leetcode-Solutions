class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            ++freq[num];
        }
        vector<int> freq_vals;
        freq_vals.reserve(freq.size());
        for (auto i = freq.begin(); i != freq.end(); ++i) {
            freq_vals.push_back(i->second);
        }
        sort(freq_vals.rbegin(), freq_vals.rend());
        while (!freq_vals.empty() && k > 0) {
            if (freq_vals.back() > k) {
                break;
            }
            k -= freq_vals.back();
            freq_vals.pop_back();
        }
        return freq_vals.size();
    }
};
