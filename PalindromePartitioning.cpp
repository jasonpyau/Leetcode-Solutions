class Solution {
public:
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> curr;

    void solve(int i, string& s) {
        if (i == s.size()) {
            // Good partition.
            ans.push_back(curr);
            return;
        }
        for (int len = 1; len <= s.size()-i; ++len) {
            if (valid(s, i, i+len-1)) {
                curr.push_back(s.substr(i, len));
                solve(i+len, s);
                curr.pop_back();
            }
        }
    }

    bool valid(string& s, int l, int r) {
        while (r > l) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
