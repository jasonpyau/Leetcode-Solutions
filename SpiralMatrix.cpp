class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = 0, dir = 0;
        int x_dir[2] = {-1, 1};
        int y_dir[2] = {1, -1};
        vector<int> ans;
        ans.reserve(m*n);
        for (int i = 0; i < n; i++, x++)
            ans.push_back(matrix[y][x]);
        m--, n--, x--;
        while (m && n) {
            for (int i = 0; i < m; i++) {
                y += y_dir[dir&1];
                ans.push_back(matrix[y][x]);
            }
            for (int i = 0; i < n; i++) {
                x += x_dir[dir&1];
                ans.push_back(matrix[y][x]);
            }
            m--, n--, dir++;
        }
        for (int i = 0; i < m; i++) {
            y += y_dir[dir&1];
            ans.push_back(matrix[y][x]);
        }
        return ans;
    }
};
