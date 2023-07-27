class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        for (int y = 2; y <= n; ++y) {
            for (int x = 1; x < y; ++x) {
                dp[y] = max({(y - x)* x, dp[y - x] * x, dp[y]});
            }
        }
        return dp[n];
    }
};