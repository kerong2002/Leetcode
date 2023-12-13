#define _for2(x, n) for (int x = 0; x < n; ++x)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        _for2(y, mat.size()) {
            _for2(x, mat[0].size()) {
                if (mat[y][x]) {
                    int tmp = 0;
                    _for2(iy, mat.size()) {
                        if (tmp == 3) {
                            break;
                        }
                        if (mat[iy][x]){
                            ++tmp;
                        }
                    }
                    _for2(ix, mat[0].size()) {
                        if (tmp == 3) {
                            break;
                        }
                        if (mat[y][ix]) {
                            ++tmp;
                        }
                    }
                    if (tmp == 2) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};