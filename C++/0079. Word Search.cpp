class Solution {
    public:
        void bfs(vector<vector<char>>& board, string word, int run, int y, int x) {
            if (run == word.size()) {
                check = true;
                return;
            }
            board[y][x] = '0';
            if (x < board[0].size() - 1 && board[y][x + 1] == word[run] && board[y][x + 1] != '0') {
                bfs(board, word, run + 1, y, x + 1);
            }
            if (y < board.size() - 1 && board[y + 1][x] == word[run] && board[y + 1][x] != '0') {
                bfs(board, word, run + 1, y + 1, x);
            }
            if (x > 0 && board[y][x - 1] == word[run] && board[y][x - 1] != '0') {
                bfs(board, word, run + 1, y, x - 1);
            }
            if (y > 0 && board[y - 1][x] == word[run] && board[y - 1][x] != '0') {
                bfs(board, word, run + 1, y - 1, x);
            }
            board[y][x] = word[run-1];
            return;
        }
        bool exist(vector<vector<char>>& board, string word) {
            if (word == "") return false;
            check = false;
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[y].size(); x++) {
                    if (board[y][x] == word[0]) {
                        bfs(board, word, 1, y, x);
                        if (check == true) {
                            return check;
                        }
                    }
                }
            }
            return check;
        }
    private:
        bool check;
};