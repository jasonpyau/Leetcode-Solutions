class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int s_freq[26];
        memset(s_freq, 0, 26*sizeof(int));
        for (int i = 0; i < s.size(); i++)
            s_freq[s[i]-'a']++;
        int targ_freq[26];
        memset(targ_freq, 0, 26*sizeof(int));
        for (int i = 0; i < target.size(); i++)
            targ_freq[target[i]-'a']++;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (targ_freq[i]) {
                if (targ_freq[i] > s_freq[i])
                    return 0;
                if (!ans) {
                    ans = s_freq[i]/targ_freq[i];
                } else {
                    ans = min(ans, s_freq[i]/targ_freq[i]);
                }
            }
        }
        return ans;
    }
};
