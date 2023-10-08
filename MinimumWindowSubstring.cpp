class Solution {
public:
    string minWindow(string s, string t) {
        // first -> l index, second -> length of substring.
        pair<int, int> ans = make_pair(0, INT_MAX);
        int matching = 0, t_unique = 0;
        int freq[52] = {0}, t_freq[52] = {0};
        // Maintain number and freq of unique chars in t.
        for (int i = 0; i < t.size(); ++i) {
            if (!t_freq[map(t[i])]++) {
                ++t_unique;
            }
        }
        for (int l = 0, r = 0; r < s.size() || matching == t_unique;) {
            if (matching == t_unique) {
                if (--freq[map(s[l])] >= t_freq[map(s[l])]) {
                    // r-1 since we incremented r without updating the freq.
                    check_ans(l+1, r-1, ans);
                } else {
                    --matching;
                }
                ++l;
                continue;
            }
            if (++freq[map(s[r])] == t_freq[map(s[r])]) {
                if (++matching == t_unique) {
                    check_ans(l, r, ans);
                }
            }
            ++r;
        }
        // No match.
        if (ans.second == INT_MAX) {
            return "";
        }
        return s.substr(ans.first, ans.second);
    }
private:
    static inline int map(char ch) {
        return ch-((ch >= 'a') ? 'a'-26 : 'A');
    }

    static inline void check_ans(int l, int r, pair<int, int>& ans) {
        if (r-l+1 < ans.second) {
            ans.first = l;
            ans.second = r-l+1;
        }
    }
};
