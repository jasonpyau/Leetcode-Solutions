bool isIsomorphic(char* s, char* t) {
    char s_map[128] = {'\0'}, t_map[128] = {'\0'};
    for (int i = 0; s[i]; ++i) {
        if (s_map[s[i]] && s_map[s[i]] != t[i]) {
            return false;
        } else if (t_map[t[i]] && t_map[t[i]] != s[i]) {
            return false;
        }
        s_map[s[i]] = t[i];
        t_map[t[i]] = s[i];
    }
    return true;
}
