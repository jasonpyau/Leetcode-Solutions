class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> word_map;
        for (string word : words) {
            auto it = word_map.find(word);
            if (it == word_map.end())
                word_map[word] = 1;
            else
                it->second++;
        }
        int word_len = words[0].size(), substr_len = words.size()*word_len;
        vector<int> ans;
        for (int i = 0; i+substr_len <= s.size(); i++) {
            unordered_map<string, int> word_map_cpy(word_map);
            for (int j = i; j < i+substr_len; j += word_len) {
                string test = s.substr(j, word_len);
                auto it = word_map_cpy.find(test);
                if (it == word_map_cpy.end()) {
                    break;
                } else {
                    it->second--;
                    if (!it->second) {
                        word_map_cpy.erase(it);
                    }
                }
            }
            if (word_map_cpy.empty())
                ans.push_back(i);
        }
        return ans;
    }
};
