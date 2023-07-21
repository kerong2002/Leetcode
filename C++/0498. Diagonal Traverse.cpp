class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        for (int t = 0; t < (m + n - 1); ++t) {
            if  (t & 1) {
                for (int y = 0; y < m; ++y) {
                    for (int x = 0; x < n; ++x) {
                        if(x + y == t) {
                            ans.push_back(mat[y][x]);
                        }
                    }
                }
            }
            else {
                for (int y = m - 1; y >= 0; --y) {
                    for (int x = n - 1; x >= 0; --x) {
                        if(x + y == t) {
                            ans.push_back(mat[y][x]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};