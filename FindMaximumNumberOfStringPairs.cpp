class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> reversed;
        int ans = 0;
        for (string word : words) {
            if (reversed.count(word)) {
                ans++;
            }
            swap(word[0], word[1]);
            reversed.insert(word);
        }
        return ans;
    }
};
