char* maximumOddBinaryNumber(char* s) {
    int n = strlen(s), freq[2] = {0};
    for (int i = 0; i < n; ++i) {
        ++freq[s[i]-'0'];
    }
    for (int i = 0; i < freq[1]-1; ++i) {
        s[i] = '1';
    }
    for (int i = freq[1]-1; i < n-1; ++i) {
        s[i] = '0';
    }
    s[n-1] = '1';
    return s;
}
