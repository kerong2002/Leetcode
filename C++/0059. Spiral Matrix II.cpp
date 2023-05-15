class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) {
            vector<vector<int>> ans(1, vector<int>(1, 0));
            ans[0][0] = 1;
            return ans;
        }
        int dx[4] = { 1, 0, -1,  0};
        int dy[4] = { 0, 1,  0, -1};
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int pos_x = 0;
        int pos_y = 0;
        int run = 0;
        int t = 0;
        while (true) {
            if(ans[pos_y][pos_x] != 0) {
                break;
            }
            ans[pos_y][pos_x] = ++run;
            if(pos_y + dy[t] >= n || pos_y + dy[t] < 0 || pos_x + dx[t] >= n || pos_x + dx[t] < 0) {
                t = (t + 1) % 4;
            }
            if (ans[pos_y + dy[t]][pos_x + dx[t]]) {
                t = (t + 1) % 4;
            }
            pos_y += dy[t];
            pos_x += dx[t];
        }
        return ans;
    }
};