int longestPalindrome(char * s) {
    int freq[52];
    memset(freq, 0, 52*sizeof(int));
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'a') {
            freq[s[i]-'a']++;
        } else {
            freq[s[i]-'A'+26]++;
        }
    }
    bool hasOdd = false;
    int ans = 0;
    for (int i = 0; i < 52; i++) {
        if (freq[i]&1) {
            hasOdd = true;
            freq[i]--;
        }
        ans += freq[i];
    }
    return ans+hasOdd;
}
