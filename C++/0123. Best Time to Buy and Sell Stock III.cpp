class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int> (5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int y = 1; y < size; ++y) {
            dp[y][0] = dp[y - 1][0];
            dp[y][1] = max(dp[y - 1][1], dp[y - 1][0] - prices[y]);
            dp[y][2] = max(dp[y - 1][2], dp[y - 1][1] + prices[y]);
            dp[y][3] = max(dp[y - 1][3], dp[y - 1][2] - prices[y]);
            dp[y][4] = max(dp[y - 1][4], dp[y - 1][3] + prices[y]);
        }
        return dp[size - 1][4];
    }
};