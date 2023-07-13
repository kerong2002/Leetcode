class Solution {
public:
    int numTilings(int n) {
        if (n < 2) {
            return 1;
        }
        int MOD = 1e9 + 7;
        vector<long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int x = 3; x <= n; ++x) {
            dp[x] = (2 * dp[x - 1] + dp[x - 3]) % MOD;
        }
        return dp[n];
    }
};