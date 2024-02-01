class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Maintain set of used values for row, col, and box.
        row = col = box = vector<vector<bool>>(N, vector<bool>(N+1, false));
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (board[r][c] != '.') {
                    int val = board[r][c]-'0';
                    row[r][val] = col[c][val] = box[get_box(r, c)][val] = true;
                }
            }
        }
        solve(0, 0, board);
    }
private:
    const int N = 9;
    vector<vector<bool>> row, col, box;

    bool solve(int r, int c, vector<vector<char>>& board) {
        if (c == N) {
            // Next row, col zero.
            return solve(r+1, 0, board);
        } else if (r == N) {
            // If we reach here, it is guaranteed we reached the one and only solution.
            return true;
        }  else if (board[r][c] != '.') {
            // This value is fixed by the original input.
            return solve(r, c+1, board);
        }
        for (int val = 1; val <= N; ++val) {
            if (row[r][val] || col[c][val] || box[get_box(r, c)][val]) {
                continue;
            }
            board[r][c] = '0'+val;
            row[r][val] = col[c][val] = box[get_box(r, c)][val] = true;
            bool found = solve(r, c+1, board);
            if (found) {
                return found;
            }
            board[r][c] = '.';
            row[r][val] = col[c][val] = box[get_box(r, c)][val] = false;
        }
        return false;
    }

    inline int get_box(int r, int c) {
        return r-r%3+c/3;
    }
};
