class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size = questions.size();
        vector<long long> dp(size + 1, 0);
        for (int x = size - 1; x >= 0; --x) {
            dp[x] = max(dp[x + 1], dp[min(x + questions[x][1] + 1, size)] + questions[x][0]);
        }
        return dp[0];
    }
};