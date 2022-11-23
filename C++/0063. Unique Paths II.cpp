class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int y_size = obstacleGrid.size();
        int x_size = obstacleGrid[0].size();
        vector<vector<int>> dp (y_size,vector<int>(x_size,0));
        if(y_size==0 || x_size==0) return 0;
        for(int y=0;y<y_size;y++){
            if(obstacleGrid[y][0]!=1){
                dp[y][0] = 1;
            }
            else{
                break;
            }
        }
        for(int x=0;x<x_size;x++){
            if(obstacleGrid[0][x]!=1){
                dp[0][x] = 1;
            }
            else{
                break;
            }
        }
        for(int y=1;y<y_size;y++){
            for(int x=1;x<x_size;x++){
                if(obstacleGrid[y][x]!=1){
                    dp[y][x] = dp[y-1][x] + dp[y][x-1];
                }
            }
        }
        return dp[y_size-1][x_size-1];
    }
};