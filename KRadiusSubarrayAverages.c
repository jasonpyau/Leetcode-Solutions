/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ll long long
int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize;
    int* ans = calloc(numsSize, sizeof(int));
    if (numsSize <= k*2) {
        memset(ans, -1, numsSize*sizeof(int));
        return ans;
    }
    memset(ans, -1, k*sizeof(int));
    memset(ans+numsSize-k, -1, k*sizeof(int));
    ll curr_sum = 0;
    for (int i = 0; i < k*2+1; i++) {
        curr_sum += nums[i];
    }
    ans[k] = curr_sum/(k*2+1.0);
    for (int i = k+1; i < numsSize-k; i++) {
        curr_sum += nums[i+k]-nums[i-k-1];
        ans[i] = curr_sum/(k*2+1.0);
    }
    return ans;
}
