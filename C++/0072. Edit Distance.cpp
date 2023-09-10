class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, 0));
        for (int y = 1; y <= word1.size(); ++y) {
            dp[y][0] = y;
        }
        for (int x = 1; x <= word2.size(); ++x) {
            dp[0][x] = x;
        }

        for (int y = 1; y <= word1.size(); ++y) {
            for (int x = 1; x <= word2.size(); ++x) {
                if (word1[y - 1] == word2[x - 1]) {
                    dp[y][x] = dp[y - 1][x - 1];
                }
                else {
                    dp[y][x] = min({dp[y - 1][x], dp[y][x - 1], dp[y - 1][x - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};