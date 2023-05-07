class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_len = s.size(), t_len = t.size();
        for (int t_i = 0, s_i = 0; t_i < t_len; t_i++) {
            char t_ch = t[t_i];
            bool contains = false;
            while (s_i < s_len) {
                if (s[s_i++] == t_ch) {
                    contains = true;
                    break;
                }
            }
            if (!contains)
                return t_len-t_i;
        }
        return 0;
    }
};
