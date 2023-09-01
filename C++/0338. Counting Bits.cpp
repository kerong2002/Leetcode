class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int x = 1; x <= n; ++x) {
            dp[x] = dp[x >> 1] + (x & 1);
        }
        return dp;
    }
};
