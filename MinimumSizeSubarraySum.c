#define min(a,b) b > a ? a : b 

int minSubArrayLen(int target, int* nums, int numsSize) {
    int l, r, sum = 0, ans = INT_MAX;
    for (int i = 0; i < numsSize && sum < target; ++i) {
        sum += nums[i];
    }
    if (sum < target) {
        return 0;
    }
    for (l = 0, r = 0, sum = 0; r < numsSize; ++r) {
        sum += nums[r];
        while (l <= r) {
            if (sum >= target) {
                ans = min(ans, r-l+1);
                sum -= nums[l++];
            } else {
                break;
            }
        }
    }
    return ans;
}
