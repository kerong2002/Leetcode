class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int y = 0; y < row; ++y) {
            for (int x = y+1; x < col; ++x) {
                swap(matrix[y][x], matrix[x][y]);
            }
        }
        
        for (int y = 0; y < row; ++y) {
            for (int x = 0; x < col / 2; ++x) {
                swap(matrix[y][x] , matrix[y][col - x - 1]);
            }
        }
        
    }
};