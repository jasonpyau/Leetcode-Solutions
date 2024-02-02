class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n, false);
        diag1 = diag2 = vector<bool>(n*2-1, false);
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        solve(0, n, curr, ans);
        return ans;
    }
private:
    vector<bool> col, diag1, diag2;

    void solve(int r, int n, vector<string>& curr, vector<vector<string>>& ans) {
        if (r == n) {
            ans.push_back(curr);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (can_do(r, c, n)) {
                // Try queen.
                curr[r][c] = 'Q';
                col[c] = diag1[get_diag1(r, c)] = diag2[get_diag2(r, c, n)] = true;
                solve(r+1, n, curr, ans);
                curr[r][c] = '.';
                col[c] = diag1[get_diag1(r, c)] = diag2[get_diag2(r, c, n)] = false;
            }
        }
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
