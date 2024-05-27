class Solution {
public:
    int checkRecord(int n) {
        vector<vector<int>> A = {{1, 1, 1, 0, 0, 0},
                                {1, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 1, 1},
                                {0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 1, 0}};
        vector<vector<int>> x = {{1},{0},{0},{0},{0},{0}};
        vector<vector<int>> b = mat_mult(mat_pow(A, n), x);
        int ans = 0;
        for (int i = 0; i < b.size(); ++i) {
            ans = add(ans, b[i][0]);
        }
        return ans;
    }
private:
    const int MOD = 1e9+7;
    using ll = long long;

    inline int add(int a, int b) {
        if (a+b >= MOD) {
            return a+b-MOD;
        }
        return a+b;
    }

    inline int mult(int a, int b) {
        return int(1ll*a*b%MOD);
    }

    vector<vector<int>> mat_identity(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            res[i][i] = 1;
        }
        return res;
    }

    vector<vector<int>> mat_mult(vector<vector<int>> a, vector<vector<int>> b) {
        assert(a[0].size() == b.size());
        int m = a.size(), n = a[0].size(), p = b[0].size();
        vector<vector<int>> res(m, vector<int>(p, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < p; ++c) {
                for (int i = 0; i < n; ++i) {
                    res[r][c] = add(res[r][c], mult(a[r][i], b[i][c]));
                }
            }
        }
        return res;
    }

    vector<vector<int>> mat_pow(vector<vector<int>> a, ll e) {
        assert(a.size() == a[0].size());
        assert(e >= 0);
        vector<vector<int>> res = mat_identity(a.size());
        while (e) {
            if (e&1) {
                res = mat_mult(res, a);
            }
            a = mat_mult(a, a);
            e >>= 1;
        }
        return res;
    }
};
