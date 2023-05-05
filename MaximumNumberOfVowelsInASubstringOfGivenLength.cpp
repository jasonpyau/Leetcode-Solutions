class Solution {
public:
    int maxVowels(string s, int k) {
        vector<bool> vis(s.size(), false);
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                ans++;
                vis[i] = true;
            }
        }
        for (int i = k, curr = ans; i < s.size() && curr != k; i++) {
            curr -= vis[i-k];
            if (isVowel(s[i])) {
                curr++;
                vis[i] = true;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
private:
    bool isVowel(char ch) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }
};
