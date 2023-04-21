#define i64 int64_t
#define MAX INT32_MAX
#define MIN INT32_MIN

static inline bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}
static inline int charToDigit(char ch) {
    return ch-'0';
}

static inline i64 addDigit(i64 num, char dig, int sign, bool* overflow) {
    num *= 10;
    num += sign*charToDigit(dig);
    if (num > MAX) {
        *overflow = true;
        return MAX;
    } else if (num < MIN) {
        *overflow = true;
        return MIN;
    }
    return num;
}

int myAtoi(char * s){
    int len = strlen(s);
    int i = 0, sign = 1;
    i64 ans = 0;
    if (!len)
        return 0;
    for (; s[i] == ' ' && i < len; i++);
    if (s[i] == '+') {
        i++;
    } else if (s[i] == '-') {
        i++;
        sign = -1;
    }
    for (; s[i] == '0' && i < len; i++);
    if (i < len && isDigit(s[i])) {
        ans = sign*charToDigit(s[i++]);
    } else {
        return 0;
    }
    bool overflow = false;
    for (; i < len && !overflow; i++) {
        char ch = s[i];
        if (isDigit(ch)) {
            ans = addDigit(ans, s[i], sign, &overflow);
        } else {
            return ans;
        }
    }
    return (int)ans;
}
