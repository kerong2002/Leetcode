#define _for2(x, end) for(int x = 0; x < end; ++x)
#define _for3(x, start, end) for(int x = start; x < end; ++x)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int> (grid[0].size() - 2, 0));
        _for2(y, grid.size() - 2) {
            _for2(x, grid[0].size() - 2) {
                int max_num = 0;
                _for3(i, y, y + 3) {
                    _for3(j, x, x + 3) {
                        max_num = max(max_num, grid[i][j]);
                    }
                }
                ans[y][x] = max_num;
            }
        }
        return ans;
    }
};