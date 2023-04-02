class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> check(row+col, -1);
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                if(check[x-y+row-1]==-1){
                    check[x-y+row-1] = matrix[y][x];
                }
                else{
                    if(check[x-y+row-1]!=matrix[y][x]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};