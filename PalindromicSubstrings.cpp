class Solution {
public:
    // O(n) exists, but O(n^2) much more intuitive.
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            // Odd or even sized.
            for (int j = 0; j <= 1; ++j) {
                for (int l = i, r = i+j; l >= 0 && r < s.size(); --l, ++r) {
                    if (s[l] != s[r]) {
                        break;
                    }
                    ++ans;
                }
            }
        }
        return ans;
    }
};
