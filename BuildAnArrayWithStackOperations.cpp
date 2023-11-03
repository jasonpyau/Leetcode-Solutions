class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for (int i = 0, stream = 1; i < target.size(); ++stream) {
            if (stream < target[i]) {
                push(ans);
                pop(ans);
            } else {
                push(ans);
                ++i;
            }
        }
        return ans;
    }
private:
    static inline void push(vector<string>& ans) {
        ans.push_back("Push");
    }

    static inline void pop(vector<string>& ans) {
        ans.push_back("Pop");
    }
};
