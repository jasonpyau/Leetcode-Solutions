class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowel_sum(words.size());
        int total_vowels = 0;
        for (int i = 0; i < words.size(); i++) {
            if ((1<<(words[i][0]-'a') & vowels) && (1<<(words[i].back()-'a') & vowels))
                total_vowels++;
            vowel_sum[i] = total_vowels;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int r = queries[i][1];
            int l = queries[i][0];
            ans[i] = (l > 0) ? vowel_sum[r]-vowel_sum[l-1] : vowel_sum[r];
        }
        return ans;
    }
private:
    int vowels = 1065233;
    // void initVowels() {
    //     vowels |= (1<<'a'-'a');
    //     vowels |= (1<<'e'-'a');
    //     vowels |= (1<<'i'-'a');
    //     vowels |= (1<<'o'-'a');
    //     vowels |= (1<<'u'-'a');
    //     cout << vowels;
    // }
};
