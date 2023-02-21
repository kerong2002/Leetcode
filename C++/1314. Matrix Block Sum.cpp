class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                if(y>0) mat[y][x] += mat[y-1][x];
                if(x>0) mat[y][x] += mat[y][x-1];
                if(x>0 && y>0) mat[y][x] -=mat[y-1][x-1];
            }
        }
        vector<vector<int>> ans(row, vector<int>(col,0));

        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                int r0 = max(0, y-k);
                int r1 = min(row-1, y+k);
                int c0 = max(0, x-k);
                int c1 = min(col-1, x+k);
                ans[y][x] = mat[r1][c1];
                if(r0>0) ans[y][x]-=mat[r0-1][c1];
                if(c0>0) ans[y][x]-=mat[r1][c0-1];
                if(r0>0 && c0>0) ans[y][x]+=mat[r0-1][c0-1];
            }
        }
        return ans;
    }
};