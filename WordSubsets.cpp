class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26, 0), freq(26);
        for (string& word : words2) {
            fill_freq_array(freq, word);
            for (int i = 0; i < 26; ++i) {
                max_freq[i] = max(max_freq[i], freq[i]);
            }
        }
        vector<string> ans;
        ans.reserve(words1.size());
        for (string& word : words1) {
            fill_freq_array(freq, word);
            bool good = true;
            for (int i = 0; i < 26; ++i) {
                good &= (freq[i] >= max_freq[i]);
            }
            if (good) {
                ans.push_back(word);
            }
        }
        return ans;
    }
private:
    void fill_freq_array(vector<int>& freq, string& s) {
        fill(freq.begin(), freq.end(), 0);
        for (char ch : s) {
            ++freq[ch-'a'];
        }
    }
};
