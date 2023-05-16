class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int y = 0; y < row; ++y) {
            if (target >= matrix[y][0]) {
                int L = 0;
                int R = col - 1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (matrix[y][mid] > target) {
                        R = mid - 1;
                    }
                    else if(matrix[y][mid] < target) {
                        L = mid + 1;
                    }
                    else {
                        ans = true;
                        break;
                    }
                }
            }
            if (ans) {
                break;
            }
        }
        return ans;
    }
};