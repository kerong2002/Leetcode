class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                if(!mat[y][x]){
                    continue;
                }
                else{
                    int up = 1e9;
                    int left = 1e9;
                    if(y>0){
                        up = mat[y-1][x];
                    }
                    if(x>0){
                        left = mat[y][x-1];
                    }
                    mat[y][x] = min(up, left) +1;
                }
            }
        }
        for(int y=row-1;y>=0;y--){
            for(int x=col-1;x>=0;x--){
                if(!mat[y][x]){
                    continue;
                }
                else{
                    int down = 1e9;
                    int right = 1e9;
                    if(y<row-1){
                        down = mat[y+1][x];
                    }
                    if(x<col-1){
                        right = mat[y][x+1];
                    }
                    
                    mat[y][x] = min(mat[y][x], min(down, right) + 1);
                }
            }
        }
        return mat;
    }
};