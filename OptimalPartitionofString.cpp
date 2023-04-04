class Solution {
public:
    int partitionString(string s) {
        int vis = 0;
        int ans = 1;
        for (int i = 0; i < s.length(); i++) {
            int ch = 1<<(s[i]-'a');
            if (vis & ch) {
                vis = 0;
                vis = ch;
                ans++;
            } else {
                vis |= ch;
            }
        }
        return ans;
    }
};
