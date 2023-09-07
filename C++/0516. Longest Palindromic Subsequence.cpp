class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), 0));
        for (int x = 0; x < s.size(); ++x) {
            dp[x][x] = 1;
        }
        for (int y = s.size() - 1; y >= 0; --y) {
            for (int x = y + 1; x < s.size(); ++x) {
                if (s[x] == s[y]) {
                    dp[y][x] = dp[y + 1][x - 1] + 2;
                }
                else {
                    dp[y][x] = max(dp[y + 1][x], dp[y][x - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};