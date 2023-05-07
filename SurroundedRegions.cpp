class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rowLen = board.size(), colLen = board[0].size();
        vis.resize(rowLen);
        for (vector<bool>& row : vis) {
            row.resize(colLen);
            fill(row.begin(), row.end(), false);
        }
        for (int r = 0; r < rowLen; r++) {
            for (int c = 0; c < colLen; c++) {
                bool isSurrounded = true;
                list<pair<int,int>> points;
                checkSurround(r, c, isSurrounded, points, board);
                if (isSurrounded) {
                    for (pair<int,int>& point : points) {
                        board[point.first][point.second] = 'X';
                    }
                }
            }
        }
    }
private:
    vector<vector<bool>> vis;
    void checkSurround(int r, int c, bool& isSurrounded, list<pair<int,int>>& points, vector<vector<char>>& board) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
            isSurrounded = false;
            return;
        } else if (board[r][c] == 'X' || vis[r][c]) {
            return;
        }
        vis[r][c] = true;
        points.push_back(make_pair(r, c));
        checkSurround(r, c-1, isSurrounded, points, board);
        checkSurround(r, c+1, isSurrounded, points, board);
        checkSurround(r-1, c, isSurrounded, points, board);
        checkSurround(r+1, c, isSurrounded, points, board);
    }
};
