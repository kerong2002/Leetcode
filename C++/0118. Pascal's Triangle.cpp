class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows,vector<int>(1,1));
        for(int y=1;y<numRows;y++){
            for(int x=1;x<y;x++){
                dp[y].push_back(dp[y-1][x-1]+dp[y-1][x]);
            }
            dp[y].push_back(1);
        }
        return dp;
    }
};