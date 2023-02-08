class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int y=2;y<=n;y++){
            for(int x=1;x<=y;x++){
               dp[y] += dp[x-1] * dp[y-x];
            }
        }
        return dp[n];
    }
};