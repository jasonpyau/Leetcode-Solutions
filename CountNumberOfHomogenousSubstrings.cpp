class Solution {
public:
    int countHomogenous(string s) {
        int ans = 1;
        // Simple arithmetic series for continuous letters.
        for (int i = 1, rep = 1; i < s.size(); ++i) {
            rep = (s[i] == s[i-1]) ? rep+1 : 1;
            ans = (ans+rep)%MOD;
        }
        return ans;
    }
private:
    const int MOD = 1e9+7;
};
