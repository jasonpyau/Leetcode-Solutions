class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int FREQ_LEN = 51;
        int suf_freq[FREQ_LEN];
        memset(suf_freq, 0, FREQ_LEN*sizeof(int));
        int suf_unique = 0;
        for (int num : nums) {
            if (!suf_freq[num]++)
                suf_unique++;
        }
        int pre_freq[FREQ_LEN];
        memset(pre_freq, 0, FREQ_LEN*sizeof(int));
        int pre_unique = 0;
        vector<int> ans;
        ans.reserve(nums.size());
        for (int num : nums) {
            if (!pre_freq[num]++)
                pre_unique++;
            if (!--suf_freq[num])
                suf_unique--;
            ans.push_back(pre_unique-suf_unique);
        }
        return ans;
    }
};
