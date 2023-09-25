class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) {
            comb(digits, 0);
        }
        return ans;
    }
private:
    vector<string> ans;
    string curr;
    vector<vector<char>> dig_to_let = {{}, 
                                {}, 
                                {'a', 'b', 'c'}, 
                                {'d', 'e', 'f'},
                                {'g', 'h', 'i'},
                                {'j', 'k', 'l'},
                                {'m', 'n', 'o'},
                                {'p', 'q', 'r', 's'},
                                {'t', 'u', 'v'},
                                {'w', 'x', 'y', 'z'}};
    void comb(string& digits, int k) {
        if (k == digits.size()) {
            ans.push_back(curr);
            return;
        }
        vector<char>& letters = dig_to_let[digits[k]-'0'];
        for (int i = 0; i < letters.size(); ++i) {
            curr.push_back(letters[i]);
            comb(digits, k+1);
            curr.pop_back();
        }
    }
};
