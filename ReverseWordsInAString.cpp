class Solution {
public:
    string reverseWords(string s) {
        string ans;
        ans.reserve(s.size());
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ' ') {
                continue;
            }
            int len = 0;
            while (i >= 0 && s[i] != ' ') {
                i--;
                len++;
            }
            for (int j = 0; j < len; j++) {
                ans += s[i+1+j];
            }
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
