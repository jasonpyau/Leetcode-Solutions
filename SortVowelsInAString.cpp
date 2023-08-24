class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowel_inds;
        vowel_inds.reserve(s.size());
        vector<char> vowels;
        vowels.reserve(s.size());
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                vowel_inds.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        for (int i = 0; i < vowel_inds.size(); ++i) {
            s[vowel_inds[i]] = vowels[i];
        }
        return s;
    }
private:
    bool isVowel(char ch) {
        switch (tolower(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    } 
};
