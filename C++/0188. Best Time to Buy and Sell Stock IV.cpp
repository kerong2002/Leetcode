class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2 * k + 1, 0));
        for(int x = 0; x < k; ++x){
            dp[0][x * 2 + 1] = -prices[0];
        }
        for (int y = 1; y < size; ++y) {
            for (int x = 1; x <= 2 * k; ++x) {
                if (x % 2 == 0) {
                    dp[y][x] = max(dp[y - 1][x], dp[y - 1][x - 1] + prices[y]);
                }
                else {
                    dp[y][x] = max(dp[y - 1][x], dp[y - 1][x - 1] - prices[y]);
                }
            }
        }
        return dp[size - 1][2 * k];
    }
};