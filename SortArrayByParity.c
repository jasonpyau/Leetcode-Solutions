/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int even_i = 0, odd_i = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i]%2 == 0) {
            ++odd_i;
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i]&1) {
            ans[odd_i++] = nums[i];
        } else {
            ans[even_i++] = nums[i];
        }
    }
    return ans;
}
