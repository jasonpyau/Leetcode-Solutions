class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& s : words) {
            if (palindrome(s)) {
                return s;
            }
        }
        return "";
    }
private:
    bool palindrome(string& s) {
        for (int l = 0, r = s.size()-1; r > l; ++l, --r) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
};
