// Solution to practice Disjoint Set.
// Time: O(n*m*inverseackermann(n*m, n*m)), or O(n*m) for any practical case.
class djset {
public:
    djset(int n) {
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

    void uni(int u, int v, vector<bool>& good) {
        u = find(u);
        v = find(v);
        if (u != v) {
            // Don't overwrite a good root.
            if (good[u]) {
                par[v] = u;
            } else {
                par[u] = v;
            }
        }
    }

private:
    vector<int> par;
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        djset dj(m*n);
        vector<bool> good(m*n, false);
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!grid[r][c]) {
                    continue;
                }
                int u = get_val(r, c, n);
                if (boundary(r, c, m, n)) {
                    // Mark the parent good since it's a one.
                    good[dj.find(u)] = true;
                }
                for (int i = 0; i < dX.size(); ++i) {
                    int v_r = r+dY[i], v_c = c+dX[i];
                    if (inbounds(v_r, v_c, m, n) && grid[v_r][v_c]) {
                        // Union the ones together.
                        int v = get_val(v_r, v_c, n);
                        dj.uni(u, v, good);
                    }
                }
            }
        }
        int ans = 0;
        for (int r = 0; r < m; ++ r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] && !good[dj.find(get_val(r, c, n))]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
private:
    vector<int> dX = {-1, 0};
    vector<int> dY = {0, -1};

    inline bool inbounds(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    inline bool boundary(int r, int c, int m, int n) {
        return (r == 0 || r+1 == m || c == 0 || c+1 == n);
    }

    inline int get_val(int r, int c, int n) {
        return r*n+c;
    }
};
