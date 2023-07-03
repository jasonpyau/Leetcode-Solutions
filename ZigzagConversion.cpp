class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> v(numRows);
        int dR = -1;
        for (int i = 0, r = 0; i < s.size(); i++, r += dR) {
            v[r].push_back(s[i]);
            if (r == 0 || r == numRows-1) {
                dR *= -1;
            }
        }
        string ans;
        ans.reserve(s.size());
        for (string& row : v) {
            ans.append(row);
        }
        return ans;
    }
};
