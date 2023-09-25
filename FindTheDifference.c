char findTheDifference(char* s, char* t) {
    int freq[26] = {0};
    for (int i = 0; s[i]; ++i) {
        ++freq[s[i]-'a'];
    }
    for (int i = 0; t[i]; ++i) {
        --freq[t[i]-'a'];
    }
    char ans;
    for (int i = 0; i < 26; ++i) {
        if (freq[i]) {
            ans = i+'a';
            break;
        }
    }
    return ans;
}
