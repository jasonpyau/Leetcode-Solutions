class Solution {
public:
    int maxSum(vector<int>& nums) {
        int map[10], ans = -1, maxDig, mapped, temp;
        memset(map, 0, 10*sizeof(int));
        for (int num : nums) {
            maxDig = 0;
            temp = num;
            while (temp) {
                maxDig = max(maxDig, temp%10);
                temp /= 10;
            }
            if ((mapped = map[maxDig])) {
                ans = max(ans, mapped+num);
            }
            map[maxDig] = max(mapped, num);
        }
        return ans;
    }
};
