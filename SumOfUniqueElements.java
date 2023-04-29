class Solution {
    public int sumOfUnique(int[] nums) {
        int[] freqs = new int[101];
        for (int num : nums)
            freqs[num]++;
        int ans = 0;
        for (int i = 0; i < freqs.length; i++)
            if (freqs[i] == 1)
                ans += i;
        return ans;
    }
}
