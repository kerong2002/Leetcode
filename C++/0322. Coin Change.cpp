class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int y = 1; y <= amount; ++y) {
            for (int x = 0; x < coins.size(); ++x) {
                if (coins[x] <= y && dp[y - coins[x]] != INT_MAX) {
                   dp[y] = min(dp[y] , dp[y - coins[x]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};