char* backspace_str(char* str, char* bs_str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#'){
            if (j > 0) j--;
            bs_str[j] = '\0';
        } else
            bs_str[j++]= str[i];
    }
    bs_str[j] = '\0';
    return bs_str;
}

bool backspaceCompare(char * s, char * t){
    char bs_s[201];
    char bs_t[201];
    backspace_str(s, bs_s);
    backspace_str(t, bs_t);
    int i = 0;
    for (; i < bs_s[i] != '\0'; i++) {
        if (bs_s[i] != bs_t[i])
            return false;
    }
    return (bs_s[i] == bs_t[i]);
}
