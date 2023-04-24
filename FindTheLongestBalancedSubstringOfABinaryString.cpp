class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        vector<int> consec;
        consec.push_back(0);
        bool lastOne = s[0]-'0';
        for (int i = 0, consec_i = 0; i < s.size(); i++) {
            int ch = s[i]-'0';
            if (ch != lastOne) {
                consec.push_back(0);
                consec_i++;
            }
            consec[consec_i]++;
            lastOne = ch;
        }
        int ans = 0;
        for (int i = s[0]-'0'+1; i < consec.size(); i += 2)
            ans = max(ans, 2*min(consec[i-1], consec[i]));
        return ans;
    }
};
