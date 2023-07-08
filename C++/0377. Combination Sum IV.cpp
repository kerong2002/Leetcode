class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target + 1, 0);
        dp[0] = 1;
        for (int y = 1; y <= target; ++y) {
            for (auto x : nums) {
                if(y >= x) {
                    dp[y] += dp[y - x];
                }
            }
        }
        return dp[target];
    }
};
