class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowels_ind(s.length());
        vector<char> vowels(s.length());
        int count = 0, v = 1065233;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]) && 1<<(tolower(s[i])-'a') & v) {
                vowels_ind[count] = i;
                vowels[count++] = s[i];
            }
        }
        for (int i = 0; count > 0; i++)
            s[vowels_ind[i]] = vowels[--count];
        return s;
    }
};
