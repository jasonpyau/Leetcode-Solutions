

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int search(int* nums, int numsSize, int target, int min, int max, int rangeItem) {
    //RANGE ITEM OF -1 -> FIRST POSITION OF TARGET
    //RANGE ITEM OF 1 -> LAST POSITION OF TARGET
    int i;
    while (max >= min) { 
        i = (min + max)/2;
        if (nums[i] == target && nums[i+rangeItem] != target)
            return i;
        else if (nums[i] == target && rangeItem == -1) 
            return search(nums, numsSize, target, 0, max-1, rangeItem);
        else if (nums[i] == target && rangeItem == 1)
            return search(nums, numsSize, target, min+1, numsSize, rangeItem);
        else if (nums[i] > target)
            max = i - 1;
        else 
            min = i + 1;
    }
    return -1;
}


int* updateRange(int *range, int left, int right) {
    //FOR PARAMETERS OF -2, DON'T UPDATE
    
    if (left != -2) range[0] = left;
    if (right != -2) range[1] = right;
    return range;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *range = malloc(sizeof(int)*2);
    *returnSize = 2;
    updateRange(range, -1, -1);
    
    //Edge cases
    if(numsSize==0) return updateRange(range, -2, -2);
    if(nums[0] == target && nums[numsSize-1] == target) return updateRange(range, 0, numsSize-1);
    if(nums[0] == target) 
        return updateRange(range, 0, search(nums, numsSize, target, 0, numsSize-1, 1));
    if(nums[numsSize-1] == target) 
        return updateRange(range, search(nums, numsSize, target, 0, numsSize-1, -1), numsSize-1);
    
    updateRange(range, search(nums, numsSize, target, 0, numsSize-1, -1), -2);
    updateRange(range, -2, search(nums, numsSize, target, 0, numsSize-1, 1));
    return range;
}
