class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> start_mp(n+1, 0), end_mp(n+1, 0);
        for (int i = 0; i < shifts.size(); ++i) {
            start_mp[shifts[i][0]] += (shifts[i][2] == 0) ? -1 : 1;
            end_mp[shifts[i][1]] += (shifts[i][2] == 0) ? -1 : 1;
        }
        string ans;
        ans.reserve(n);
        for (int i = 0, shift = 0; i < n; ++i) {
            shift += start_mp[i];
            ans.push_back((s[i]-'a'+26+shift%26)%26+'a');
            shift -= end_mp[i];
        }
        return ans;
    }
};
