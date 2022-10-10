int removeDuplicates(int* nums, int numsSize){
    int nonDupes = (numsSize > 0) ? 1 : 0;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i-1] == nums[i])
            continue;
        else {
            nums[nonDupes++] = nums[i];
        }
    }
    return nonDupes;
}
