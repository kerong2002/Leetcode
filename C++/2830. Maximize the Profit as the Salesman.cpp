class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0);
        vector<vector<pair<int, int>>>  v(n + 1);
        for (auto data : offers) {
            v[data[1] + 1].push_back({data[0] + 1, data[2]});
        }
        for (int y = 1; y <= n; ++y) {
            dp[y] = dp[y - 1];
            for (auto& [prev, coin] : v[y]) {
                dp[y] = max(dp[y], dp[prev - 1] + coin);
            }
        }
        return dp[n];
    }
};
