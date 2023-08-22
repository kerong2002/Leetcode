#define SET ios_base::sync_with_stdio(0),\
            cin.tie(0),\
            cout.tie(0)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        SET;
        int small = INT_MAX;
        int big = INT_MIN;
        for (auto x : pairs) {
            small = min(small, x[0]);
            big = max(big, x[1]);
        }
        if (small >= 0) {
            small = 0;
        }
        small -= 1;
        int m = abs(small) + big;
        vector<vector<int>> v1(m + 1);

        for (auto y : pairs) {
            v1[y[1] + abs(small)].push_back(y[0] + abs(small));
        }


        vector<int> dp(m + 1, 0);
        for (int y = 1; y <= m; ++y) {
            dp[y] = dp[y - 1];
            for (auto prev : v1[y]) {
                dp[y] = max(dp[y], dp[prev - 1] + 1);
            }
        }


        return dp[m];
    }
};