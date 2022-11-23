class Solution {
public:
    int uniquePaths(int m, int n) {
        int **dp = new int *[n+1]();
        for(int y=0;y<n+1;y++){
            dp[y] = new int[m+1]();
        }
        dp[n-1][m-1]=1;
        for(int y=n-1;y>=0;y--){
            for(int x=m-1;x>=0;x--){
                dp[y][x]+=dp[y][x+1];
                dp[y][x]+=dp[y+1][x];
            }
        }
        return dp[0][0];
    }
};