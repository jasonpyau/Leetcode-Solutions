/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i = 0, j = numbersSize-1;
    int* ans = malloc(2*sizeof(int));
    *returnSize = 2;
    while (j > i) {
        if (target < numbers[i]+numbers[j]) {
            --j;
        } else if (target > numbers[i]+numbers[j]) {
            ++i;
        } else {
            ans[0] = i+1;
            ans[1] = j+1;
            break;
        }
    }
    return ans;
}
