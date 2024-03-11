char* customSortString(char* order, char* s) {
    int freq[26] = {0}, res_i = 0;
    char* res = malloc((strlen(s)+1)*sizeof(char));
    for (int i = 0; s[i]; ++i) {
        ++freq[s[i]-'a'];
    }
    for (int i = 0; order[i]; ++i) {
        char ch = order[i];
        while (freq[ch-'a']) {
            res[res_i++] = ch;
            --freq[ch-'a'];
        }
    }
    for (int i = 0; i < 26; ++i) {
        while (freq[i]) {
            res[res_i++] = i+'a';
            --freq[i];
        }
    }
    res[res_i] = '\0';
    return res;
}
