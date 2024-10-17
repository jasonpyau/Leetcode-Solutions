#define INIT (-1)

int maximumSwap(int num) {
    char s[10] = {'\0'};
    sprintf(s, "%d", num);
    int map[10];
    memset(map, INIT, 10*sizeof(int));
    for (int i = strlen(s)-1; i >= 0; --i) {
        if (map[s[i]-'0'] == INIT) {
            map[s[i]-'0'] = i;
        }
    }
    for (int i = 0; s[i]; ++i) {
        for (int j = 9; j > s[i]-'0'; --j) {
            if (map[j] != INIT && map[j] > i) {
                s[map[j]] = s[i];
                s[i] = j+'0';
                return atoi(s);
            }
        }
    }
    return num;
}
