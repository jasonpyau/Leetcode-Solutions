class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26, -1);
        int ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            int j = s[i]-'a';
            if (start[j] == -1) {
                start[j] = i;
            } else {
                ans = max(ans, i-start[j]-1);
            }
        }
        return ans;
    }
};
