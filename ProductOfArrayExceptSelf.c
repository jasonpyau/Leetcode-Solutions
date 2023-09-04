/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int mult, i;
    for (i = 0, mult = 1; i < numsSize; ++i) {
        ans[i] = mult;
        mult *= nums[i];
    }
    for (i = numsSize-1, mult = 1; i >= 0; --i) {
        ans[i] *= mult;
        mult *= nums[i];
    }
    return ans;
}
