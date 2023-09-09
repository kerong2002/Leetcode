class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (auto y : candidates) {
            for (int x = y; x <= target; ++x) {
                for (auto t : dp[x - y]) {
                    t.push_back(y);
                    dp[x].push_back(t);
                }
            }
        }
        return dp[target];
    }
};