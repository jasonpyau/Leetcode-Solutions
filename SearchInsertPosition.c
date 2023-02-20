int searchInsert(int* nums, int numsSize, int target){
    int min = 0, max = numsSize - 2;
    if (nums[0] >= target)
        return 0;
    else if (nums[numsSize-1] < target)
        return numsSize;
    while (max >= min) {
        int i = (min+max)/2;
        if (nums[i] == target)
            return i;
        else if (nums[i+1] == target)
            return i+1;
        else if (nums[i] < target && nums[i+1] > target)
            return i+1;
        else if (nums[i] > target)
            max = i-1;
        else 
            min = i+1;
    }
    return -1;
}
