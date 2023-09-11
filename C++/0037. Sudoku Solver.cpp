class Solution {
public:
    bool isValid(int row, int col, char key, vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == key) {
                return false;
            }
        }
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == key) {
                return false;
            }
        }
        int of_y = (row / 3) * 3;
        int of_x = (col / 3) * 3;
        for (int i = of_y; i < of_y + 3; ++i) {
            for (int j = of_x; j < of_x + 3; ++j) {
                if (board[i][j] == key) {
                    return false;
                }
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board) {
        for (int y = 0; y < 9; ++y) {
            for (int x = 0; x < 9; ++x) {
                if (ispunct(board[y][x])) {
                    for (char t = '1'; t <= '9'; ++t) {
                        if (isValid(y, x, t, board)) {
                            board[y][x] = t;
                            if (backtracking(board)) {
                                return true;
                            }
                            else {
                                board[y][x] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
        return;
    }
};