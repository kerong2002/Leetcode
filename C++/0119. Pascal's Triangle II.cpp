class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1,1);
        for(int y=2;y<=rowIndex;y++){
            for(int x=y-1;x>=1;x--){
                dp[x] = dp[x-1] + dp[x];
            }
        }
        return dp;
    }
};