class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        // initVowels();
        int ans = 0;
        for (int i = left; i <= right; i++)
            if (1<<(words[i][0]-'a') & vowels && 1<<(words[i].back()-'a') & vowels)
                ans++;
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
