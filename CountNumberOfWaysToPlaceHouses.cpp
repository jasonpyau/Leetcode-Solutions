// We have F_n = F_(n-1)+F_(n-2), for n >= 3. F_1 = 2, F_2 = 3.
// Also, we have F_(n-1) = F_(n-1).
// Represent as matrix (Ax = b):
// | F_n     |     | 1 1 |   |F_(n-1)|
// | F_(n-1) |  =  | 1 0 | * |F_(n-2)|
// Then:
// | F_(n-1) |     | 1 1 |   |F_(n-2)|
// | F_(n-2) |  =  | 1 0 | * |F_(n-3)|
// So, we have:
// | F_n     |     | 1 1 |   | 1 1 |   |F_(n-2)|
// | F_(n-1) |  =  | 1 0 | * | 1 0 | * |F_(n-3)|
// In general, we have:
// | F_n     |     | 1 1 |^(n-2)   | 3 |
// | F_(n-1) |  =  | 1 0 |       * | 2 |

class Solution {
public:
    // O(log(n)).
    int countHousePlacements(int n) {
        // Each side:
        // n = 1: 2
        // n = 2: 3
        // n > 2: If n-1 has house, no house. Else, 2 choices.
        // Basically, F_n = F_(n-1)+F_(n-2) for each side.
        if (n == 1) {
            return 2*2;
        }
        vector<vector<int>> a = {{1,1},{1,0}};
        vector<vector<int>> b = mat_pow(a, n-2);
        vector<vector<int>> c = mat_mult(b, {{3},{2}});
        int f_n = c[0][0];
        // Two independent sides.
        return mult(f_n, f_n);
    }
private:
    const int MOD = 1e9+7;

    inline int add(int a, int b) {
        if (a+b >= MOD) {
            return a+b-MOD;
        }
        return a+b;
    }

    inline int mult(int a, int b) {
        return 1ll*a*b%MOD;
    }

    vector<vector<int>> identity(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            res[i][i] = 1;
        }
        return res;
    }

    vector<vector<int>> mat_mult(vector<vector<int>> a, vector<vector<int>> b) {
        assert(a[0].size() == b.size());
        vector<vector<int>> res(a.size(), vector<int>(b[0].size()));
        for (int r = 0; r < res.size(); ++r) {
            for (int c = 0; c < res[0].size(); ++c) {
                for (int i = 0; i < b.size(); ++i) {
                    res[r][c] = add(res[r][c], mult(a[r][i], b[i][c]));
                }
            }
        }
        return res;
    }

    vector<vector<int>> mat_pow(vector<vector<int>> a, int e) {
        assert(a.size() == a[0].size());
        assert(e >= 0);
        vector<vector<int>> res = identity(a.size());
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
