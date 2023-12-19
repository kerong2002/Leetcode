#define _for2(x, n) for(int x = 0; x < n; ++x)
class Solution {
public:
    bool overflow(int y, int x, int y_size, int x_size) {
        if (x < 0 || y < 0 || x >= x_size || y >= y_size) {
            return false;
        }
        else {
            return true;
        }
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();
        int dy[] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
        int dx[] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
        vector<vector<int>> dp(row, vector<int> (col, 0));
        _for2 (y, row) {
            _for2 (x, col) {
                int sum = 0;
                int cnt = 0;
                _for2 (s, 9) {
                    if (overflow(y + dy[s], x + dx[s], row, col)) {
                        ++cnt;
                        sum += img[y + dy[s]][x + dx[s]];
                    }
                }
                dp[y][x] = sum / cnt;
            }
        }
        return dp;
    }
};