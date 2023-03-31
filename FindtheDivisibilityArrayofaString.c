/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define ll long long
int* divisibilityArray(char * word, int m, int* returnSize){
    int i;
    ll mod = 0;
    int* ans = (int*)calloc((size_t)1e5, sizeof(int));
    for (i = 0; word[i] != '\0'; i++) {
        char ch = word[i];
        mod *= 10;
        mod = (ch-'0'+mod)%m;
        ans[i] = (mod == 0) ? 1 : 0;
    }
    ans = (int*)realloc(ans, i*sizeof(int));
    *returnSize = i;
    return ans;
}
