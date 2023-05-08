class Solution {
private:
    const int dx[8] = { -1,  0,  1, -1,  1, -1, 0, 1};
    const int dy[8] = { -1, -1, -1,  0,  0,  1, 1, 1};
public:
    int checkNeighbor(vector<vector<int>> &board, int y, int x) {
        int number = 0;
        for (int t = 0; t < 8; ++t) {
            int new_y = y + dy[t];
            int new_x = x + dx[t];
            if (new_y <0 || new_x < 0 || new_y >= board.size() || new_x >= board[0].size()){
                continue;
            }
            if (board[new_y][new_x]) {
                ++number;
            }
        }
        return number;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (size_t y = 0; y < row; ++y) {
            for (size_t x = 0; x < col; ++x) {
                int cnt = checkNeighbor(board, y, x);
                if (cnt >= 2 && cnt <= 3 && board[y][x]) {
                    ans[y][x] = board[y][x];
                }
                else if (cnt == 3 && !board[y][x]) {
                    ans[y][x] = 1;
                }
            }
        }
        board = ans;
    }
};