class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> curr_len;
        curr_len.push(0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                curr_len.push(0);
            } else {
                if (curr_len.size() == 1) {
                    curr_len.top() = 0;
                } else {
                    int val = curr_len.top()+2;
                    curr_len.pop();
                    curr_len.top() += val;
                    ans = max(ans, curr_len.top());
                }
            }
        }
        return ans;
    }
};
