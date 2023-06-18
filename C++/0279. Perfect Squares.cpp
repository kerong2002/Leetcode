class Solution {
public:
    int numSquares(int n) {
        int max_square = static_cast<int> (sqrt(n));
        vector<int> square;
        for (int x = 1; x <= max_square; ++x) {
            square.push_back(x * x);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int y = 1; y <= n; ++y) {
            for (auto val : square) {
                if (y >= val && dp[y - val] != INT_MAX) {
                    dp[y] = min(dp[y], dp[y - val] + 1);
                }
            }
        }

        return dp[n];
    }
};