class Solution {
public:
    int minimumLength(string s) {
        int ans = s.size(), l = 0, r = s.size()-1;
        while (r > l) {
            while (l+1 < r && s[l] == s[l+1]) {
                ++l;
            }
            while (r-1 > l && s[r] == s[r-1]) {
                --r;
            }
            if (s[l] == s[r]) {
                ++l, --r;
                ans = r-l+1;
            } else {
                break;
            }
        }
        return ans;
    }
};
