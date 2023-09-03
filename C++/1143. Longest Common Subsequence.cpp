class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.size();
        int col = text2.size();
        vector<vector<int>> dp(row + 1, vector<int> (col + 1, 0));
        for (int y = 1; y <= row; ++y) {
            for (int x = 1; x <= col; ++x) {
                if (text1[y - 1] == text2[x - 1]) {
                    dp[y][x] = dp[y - 1][x - 1] + 1;
                }
                else {
                    dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
                }
            }
        }
        return dp[row][col];
    }
};