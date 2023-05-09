class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<uint32_t,int> freqs;
        int ans = 0;
        for (string& word : words) {
            ans += freqs[createKey(word)]++;
        }
        return ans;
    }
private:
    uint32_t createKey(string word) {
        uint32_t key = 0;
        for (int i = 0; i < word.size(); i++)
            key |= 1<<(word[i]-'a');
        return key;
    }
};
