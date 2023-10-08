class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        this->n = n;
        generate(0, 0);
        return ans;
    }
private:
    vector<string> ans;
    string curr;
    int n;

    void generate(int open, int closed) {
        if (curr.size() == n*2) {
            ans.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            generate(open+1, closed);
            curr.pop_back();
        }
        if (open > closed) {
            curr.push_back(')');
            generate(open, closed+1);
            curr.pop_back();
        }
    }
};
