/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    int* ans = (int*)calloc(2, sizeof(int));
    ans[0] = 0;
    ans[1] = 0;
    for (int i = 0; n; i++) {
        if (n % 2 == 1) 
            ans[i%2]++;
        n >>= 1;
    }
    *returnSize = 2;
    return ans;
}
