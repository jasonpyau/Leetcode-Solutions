class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int n = s.size(), count = 0;
        pair<char,char> diff1, diff2;
        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) {
                if (!count) {
                    diff1 = make_pair(s[i], goal[i]);
                } else if (count == 1) {
                    diff2 = make_pair(s[i], goal[i]);
                } else {
                    return false;
                }
                count++;
            }
        }
        if (count == 2) {
            return (diff1.first == diff2.second && diff2.first == diff1.second);
        } else if (count == 1) {
            return false;
        }
        // Same string should have repeating.
        int freq[26];
        memset(freq, 0, 26*sizeof(int));
        for (int i = 0; i < n; i++) {
            if (++freq[s[i]-'a'] == 2) {
                return true;
            }
        }
        return false;
    }
};
