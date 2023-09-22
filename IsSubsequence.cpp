class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_i, t_i;
        for (s_i = 0, t_i = 0; t_i < t.size(); ++t_i) {
            if (s[s_i] == t[t_i]) {
                if (++s_i == s.size()) {
                    break;
                }
            }
        }
        return (s_i == s.size());
    }
};
