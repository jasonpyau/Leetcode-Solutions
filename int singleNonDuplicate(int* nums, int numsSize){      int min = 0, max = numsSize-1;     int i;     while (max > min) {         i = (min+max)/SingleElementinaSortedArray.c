int singleNonDuplicate(int* nums, int numsSize){

    int min = 0, max = numsSize-1;
    int i;
    while (max > min) {
        i = (min+max)/2;
        if (i % 2 == 1)
            i--;
        if (nums[i] != nums[i+1])
            max = i-1;
        else 
            min = i+2;
    }
    return nums[min];
}
