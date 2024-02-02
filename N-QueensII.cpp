class Solution {
public:
    int totalNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = diag2 = vector<bool>(n*2-1, false);
        return solve(0, n);
    }
private:
    vector<bool> col, diag1, diag2;

    int solve(int r, int n) {
        if (r == n) {
            return 1;
        }
        int res = 0;
        for (int c = 0; c < n; ++c) {
            if (can_do(r, c, n)) {
                // Try queen.
                col[c] = diag1[get_diag1(r, c)] = diag2[get_diag2(r, c, n)] = true;
                res += solve(r+1, n);
                col[c] = diag1[get_diag1(r, c)] = diag2[get_diag2(r, c, n)] = false;
            }
        }
        return res;
    }

    bool can_do(int r, int c, int n) {
        return !(col[c] || diag1[get_diag1(r, c)] || diag2[get_diag2(r, c, n)]);
    }

    inline int get_diag1(int r, int c) {
        return r+c;
    }

    inline int get_diag2(int r, int c, int n) {
        return n-r-1+c;
    }
};
