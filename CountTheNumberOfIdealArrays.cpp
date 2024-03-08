// O(maxValue^(3/2)*min(n,log(maxValue))+max(n, maxValue)).
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        setUp(max(n, maxValue));
        // Number of valid paths for val i of length k.
        // Length of valid path is # unique values from 1 to val.
        // Ex of valid path: [1,2,4,8,32,96].
        vector<vector<int>> path_lens(maxValue+1, vector<int>(min(n+1, log2(maxValue)+2), 0));
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = 2; j*j <= i; ++j) {
                if (i%j) {
                    continue;
                }
                for (int k = 1; k < path_lens[i].size(); ++k) {
                    path_lens[i][k] = add(path_lens[i][k], path_lens[j][k-1]);
                    // Don't double count i to valid path of j!
                    if (j*j != i) {
                        path_lens[i][k] = add(path_lens[i][k], path_lens[i/j][k-1]);
                    }
                }
            }
            // i to i.
            path_lens[i][1] = add(path_lens[i][1], 1);
            // i to 1.
            if (i > 1) {
                path_lens[i][2] = add(path_lens[i][2], 1); 
            }
        }
        // Stars and bars in combinatorics.
        // n balls, j bins.
        // But, to make it disjoint, each bin needs at least 1 ball!
        int ans = 0;
        for (int i = 0; i <= maxValue; ++i) {
            for (int j = 1; j < path_lens[i].size(); ++j) {
                ans = add(ans, mult(path_lens[i][j], nCr(n-1, j-1)));
            }
        }
        return ans;
    }
private:
    const int MOD = 1e9+7;
    vector<int> fact, inv_fact;

    int log2(int n) {
        int res = -1;
        assert(n > 0);
        while (n) {
            ++res;
            n >>= 1;
        }
        return res;
    }

    int add(int a, int b) {
        if (a+b >= MOD) {
            return a+b-MOD;
        }
        return a+b;
    }

    int mult(int a, int b) {
        return 1ll*a*b%MOD;
    }

    int pow(int n, int e) {
        if (!e) {
            return 1;
        } else if (e&1) {
            return mult(n, pow(n, e-1));
        } else {
            int srt = pow(n, e>>1);
            return mult(srt, srt);
        }
    }

    int inv(int n) {
        // Fermat's little theorem for prime modulo.
        return pow(n, MOD-2);
    }

    int nCr(int n, int r) {
        if (n-r < 0) {
            return 0;
        }
        return mult(fact[n], mult(inv_fact[r], inv_fact[n-r]));
    }

    void setUp(int n) {
        fact = inv_fact = vector<int>(n+1);
        // Pre calculate factorials. 
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = mult(fact[i-1], i);
        }
        inv_fact[n] = inv(fact[n]);
        for (int i = n-1; i >= 0; --i) {
            inv_fact[i] = mult(inv_fact[i+1], i+1);
        }
    }
};
