class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        int dx[4] = {1, 0, -1,  0};
        int dy[4] = {0, 1,  0, -1};
        for (int y = 0; y < row; ++y) {
            for (int x = 0; x < col; ++x) {
                if (grid[y][x]) {
                    for (int k = 0; k < 4; ++k) {
                        int newX = x + dx[k];
                        int newY = y + dy[k];
                        if (newX < 0 || newY < 0) {
                            ++ans;
                        }
                        else if (newX >= col || newY >= row) {
                            ++ans;
                        }
                        else if (grid[newY][newX] == 0) {
                            ++ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};