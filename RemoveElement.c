int removeElement(int* nums, int numsSize, int val) {

    int offset = 0;
    for (int i = 0; i < numsSize; i++)  {
        if (nums[i] == val) {
            offset++;
        } else {
            nums[i-offset] = nums[i];
        }
    }
    return numsSize-offset;
}
