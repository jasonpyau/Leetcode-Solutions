class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> first_occur;
        stack<int> good_ind;
        for (int i = 0; i < nums.size(); ++i) {
            if (!first_occur.count(nums[i])) {
                first_occur[nums[i]] = i;
            } else {
                int curr = first_occur[nums[i]];
                while (!good_ind.empty() && good_ind.top() >= curr) {
                    good_ind.pop();
                }
            }
            good_ind.push(i);
        }
        // Can't partition at end of array.
        good_ind.pop();
        // Can choose to partition or not in the good indices.
        return pow(2, good_ind.size());
    }
private:
    const int MOD = 1e9+7, INF = 1e5+1;
    
    int pow(int n, int e) {
        if (!e) {
            return 1;
        } else if (e&1) {
            return 1ll*n*pow(n, e-1)%MOD;
        } else {
            int sqt = pow(n, e>>1);
            return 1ll*sqt*sqt%MOD;
        }
    }
};
