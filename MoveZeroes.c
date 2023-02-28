void moveZeroes(int* nums, int numsSize){
    int nonZeros = 0;
    for (int i = 0; i < numsSize; i++) {
        nums[nonZeros] = nums[i];
        if (nums[i] != 0)
            nonZeros++;
    }
    for (int i = nonZeros; i < numsSize; i++)
        nums[i] = 0;
}
