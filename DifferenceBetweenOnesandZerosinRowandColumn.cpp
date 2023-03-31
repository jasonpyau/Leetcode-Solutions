class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> row(grid.size()*2);
        vector<int> col(grid[0].size()*2);
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                row[r*2+grid[r][c]]++;
                col[c*2+grid[r][c]]++; 
            }
        }
        vector<vector<int>> ans(grid.size());
        for (int r = 0; r < grid.size(); r++) {
            vector<int> ansRow (grid[0].size());
            for (int c = 0; c < grid[0].size(); c++) {
                int zerosRow = row[r*2];
                int onesRow = row[r*2+1];
                int zerosCol = col[c*2];
                int onesCol = col[c*2+1];
                ansRow[c] = onesRow+onesCol-zerosRow-zerosCol;
            }
            ans[r] = ansRow;
        }
        return ans;
    }
};
