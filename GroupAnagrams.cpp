class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string str : strs) {
            int freq[26];
            memset(freq, 0, 26*sizeof(int));
            for (int i = 0; i < str.size(); i++)
                freq[str[i]-'a']++;
            string key;
            key.reserve(str.size());
            for (int i = 0; i < 26; i++) {
                char ch = i+'a';
                for (int j = 0; j < freq[i]; j++) {
                    key += ch;
                }
            }
            groups[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it : groups) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
