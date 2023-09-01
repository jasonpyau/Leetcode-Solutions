/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define min(a,b) (b > a) ? a : b

char ** commonChars(char ** words, int wordsSize, int* returnSize) {
    int freq[26] = {0};
    for (int i = 0; words[0][i]; ++i) {
        ++freq[words[0][i]-'a'];
    }
    int curr[26];
    for (int i = 0; i < wordsSize; ++i) {
        memset(curr, 0, 26*sizeof(int));
        for (int j = 0; words[i][j]; ++j) {
            ++curr[words[i][j]-'a'];
        }
        for (int j = 0; j < 26; ++j) {
            freq[j] = min(freq[j], curr[j]);
        }
    }
    char** ans = malloc(100*sizeof(char*));
    int a_i = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            ans[a_i] = malloc(2*sizeof(char));
            ans[a_i][0] = 'a'+i;
            ans[a_i++][1] = '\0';
        }
    }
    ans = realloc(ans, a_i*sizeof(char*));
    *returnSize = a_i;
    return ans;
}
