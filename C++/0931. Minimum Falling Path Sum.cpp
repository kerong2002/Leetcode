class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MAX;
        if(row==1){
            for(int x=0;x<col;x++){
                ans = min(matrix[0][x], ans);
            }
            return ans;
        }
        for(int y=row-2;y>=0;y--){
            for(int x=col-1;x>=0;x--){
                if(x==col-1){
                    matrix[y][x] += min(matrix[y+1][x], matrix[y+1][x-1]);
                }
                else if(x==0){
                    matrix[y][x] += min(matrix[y+1][x], matrix[y+1][x+1]);
                }
                else{
                    matrix[y][x] += min({matrix[y+1][x-1], matrix[y+1][x], matrix[y+1][x+1]});
                }
                if(y==0){
                    ans = min(matrix[y][x], ans);
                }
            }
        }
        return ans;
    }
};