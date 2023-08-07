class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int L = 0;
        int H = (row * col) - 1;
        while(L <= H) {
            int mid = (L + H) >> 1;
            if(matrix[mid / col][mid % col] == target) {
                return true;
            }
            else if(matrix[mid / col][mid % col] > target) {
                H = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        return false;
    }
};