class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num : nums) {
            if (++map[num] == 3) {
                map.erase(num);
            }
        }
        return map.begin()->first;
    }
};
