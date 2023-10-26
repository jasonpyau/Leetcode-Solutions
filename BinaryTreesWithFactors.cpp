typedef long long ll;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        s.insert(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            // Take each value as root of tree.
            ans = (ans+solve(arr[i], arr))%MOD;
        }
        return ans;
    }
private:
    unordered_map<int, int> memo;
    unordered_set<int> s;
    const int MOD = 1e9+7;

    int solve(int val, vector<int>& arr) {
        if (memo[val]) {
            return memo[val];
        }
        int total = 1;
        for (int i = 0; i < arr.size() && 1ll*arr[i]*arr[i] <= val; ++i) {
            if (val%arr[i]) {
                continue;
            }
            // val = arr[i]*x, where x = arr[j] for 0 <= j <= i.
            int x = val/arr[i];
            if (s.count(x)) {
                // Can pick any valid tree for left and right child.
                ll comb = 1ll*solve(arr[i], arr)*solve(x, arr);
                if (val/x == x) {
                    total = (total+comb)%MOD;
                } else {
                    // Can also flip the children.
                    total = (total+2*comb)%MOD;
                }
            }
        }
        return memo[val] = total;
    }
};
