class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size()-1;
        int score = 0, ans = 0;
        while (r >= l) {
            if (power >= tokens[l]) {
                // Face-up.
                ans = max(ans, ++score);
                power -= tokens[l++];
            } else if (score >= 1) {
                // Face-down.
                --score;
                power += tokens[r--];
            } else {
                // Can't do anything else.
                break;
            }
        }
        return ans;
    }
};
