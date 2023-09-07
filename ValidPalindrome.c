bool isPalindrome(char * s) {
    int len = strlen(s);
    char convert[len];
    int i, j;
    for (i = 0, j = 0; i < len; ++i) {
        if (isalnum(s[i])) {
            convert[j++] = tolower(s[i]);
        }
    }
    for (i = 0, --j; j > i; ++i, --j) {
        if (convert[i] != convert[j]) {
            return false;
        }
    }
    return true;
}
