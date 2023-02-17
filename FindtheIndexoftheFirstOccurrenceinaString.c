int strStr(char * haystack, char * needle){
    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            for (int k = 0;; k++) {
                if (needle[k] == '\0')
                    return i;
                if (haystack[i+k] != needle[k])
                    break;
            }
        }
    }
    return -1;
}
