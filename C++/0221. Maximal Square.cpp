class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int y=0;y<row;y++){
            for(int x=0;x<col;x++){
                dp[y][x] = matrix[y][x] - '0';
                if(x!=0 && y!=0 && dp[y][x]==1){
                    dp[y][x] = min({dp[y-1][x-1], dp[y][x-1], dp[y-1][x]}) + dp[y][x];
                }
                ans = max(ans, dp[y][x]);
            }
        }
        return ans * ans;
    }
};