int compareTo(const int* a, const int* b) {
    return *a-*b;
}

int findNonMinOrMax(int* nums, int numsSize) {
    if (numsSize < 3) {
        return -1;
    }
    qsort(nums, 3, sizeof(int), &compareTo);
    return nums[1];
}
