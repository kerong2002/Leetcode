class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int> (row, 0));
        for (int y = 0; y < row; ++y) {
            for (int x = 0; x < col; ++x) {
                ans[x][y] = matrix[y][x];
            }
        }
        return ans;
    }
};