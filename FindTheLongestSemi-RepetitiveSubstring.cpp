class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i = 1;
        // Get 2nd digit of first pair
        while (s[i-1] != s[i] && i < s.size()) {
            i++;
        }
        if (i == s.size()) {
            return i;
        }
        int last = i, ans = ++i;
        for (int curr = ans; i < s.size(); i++) {
            if (s[i-1] == s[i]) {
                curr = i-last;
                last = i;
            }
            ans = max(ans, ++curr);
        }
        return ans;
    }
};
