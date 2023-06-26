class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int x = 1; x < size; ++x) {
            dp[x][0] = max(dp[x - 1][0], -prices[x]);
            dp[x][1] = max(dp[x - 1][1], dp[x][0] + prices[x]);
        }
        return dp[size - 1][1];
    }
};