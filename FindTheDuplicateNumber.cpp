class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, res = -1, high = nums.size()-1;
        while (high >= low) {
            int mid = (low+high)>>1;
            int freq = 0;
            for (int num : nums) {
                freq += (num <= mid);
            }
            if (freq > mid) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return res;
    }
};
