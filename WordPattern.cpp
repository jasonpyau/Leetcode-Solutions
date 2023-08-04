class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> letter_to_word(26);
        unordered_set<string> used_words;
        int p_i, s_l, s_r;
        string curr;
        for (p_i = 0, s_l = 0; p_i < pattern.size() && s_l < s.size(); ++p_i) {
            for (s_r = s_l; s_r < s.size(); ++s_r) {
                if (s[s_r] == ' ') {
                    break;
                }
            }
            curr = s.substr(s_l, s_r-s_l);
            string& mapped_word = (letter_to_word[pattern[p_i]-'a']);
            if (mapped_word.empty()) {
                if (used_words.count(curr)) {
                    return false;
                }
                mapped_word = curr;
                used_words.insert(curr);
            } else {
                if (curr != mapped_word) {
                    return false;
                }
            }
            s_l = (s_r == s.size()) ? s_r : s_r+1;
        }
        return (p_i == pattern.size() && s_l == s.size());
    }
};
