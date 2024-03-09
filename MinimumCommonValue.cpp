class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                ++j;
            } else if (nums2[j] > nums1[i]) {
                ++i;
            } else {
                return nums1[i];
            }
        }
        return -1;
    }
};
