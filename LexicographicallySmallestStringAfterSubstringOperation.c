char * smallestString(char* s) {
    int len = strlen(s), i = 0;
    bool did_operation = false;
    while (s[i] == 'a' && i < len-1) {
        i++;
    }
    for (; i < len; i++) {
        if (s[i] == 'a') {
            if (!did_operation) {
                s[i] = 'z';
            }
            break;
        } else {
            s[i]--;
            did_operation = true;
        }
    }
    return s;
}
