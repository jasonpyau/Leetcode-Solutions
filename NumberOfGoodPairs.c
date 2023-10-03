int numIdenticalPairs(int* nums, int numsSize) {
    int freq[101] = {0}, ans = 0;
    for (int i = 0; i < numsSize; ++i) {
        ans += freq[nums[i]]++;
    }
    return ans;
}
