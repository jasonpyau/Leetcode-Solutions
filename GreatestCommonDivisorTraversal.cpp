class disjoint_set {
public:
    disjoint_set(int n) {
        par = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int u) {
        if (par[u] == u) {
            return u;
        }
        return par[u] = find(par[u]);
    }

    bool uni(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            par[u] = v;
            return true;
        }
        return false;
    }
private:
    vector<int> par;
};

class Solution {
public:
    // O(n*sqrt(MAX_VAL)).
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> factor_map;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j*j <= nums[i]; ++j) {
                if (nums[i]%j == 0) {
                    factor_map[j].push_back(i);
                    factor_map[nums[i]/j].push_back(i);
                }
            }
        }
        disjoint_set dj(n);
        int ans = 0;
        for (auto it = factor_map.begin(); it != factor_map.end(); ++it) {
            if (it->first == 1) {
                // Can only do for factors i > 1.
                continue;
            }
            vector<int>& inds = it->second;
            for (int i = 1; i < inds.size(); ++i) {
                if (dj.uni(inds[i-1], inds[i])) {
                    ++ans;
                }
            }
        }
        return (ans == n-1);
    }
};
