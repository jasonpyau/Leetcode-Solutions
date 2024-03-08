const int MAX_VAL = 100;

int maxFrequencyElements(int* nums, int numsSize) {
    int freq[MAX_VAL+1];
    memset(freq, 0, (MAX_VAL+1)*sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        ++freq[nums[i]];
    }
    int max_freq = 0, ans = 0;
    for (int i = 1; i <= MAX_VAL; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            ans = freq[i];
        } else if (freq[i] == max_freq) {
            ans += freq[i];
        }
    }
    return ans;
}
