class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> dp(nums.size(), 0);
        dp[nums.size() - 1] = nums[nums.size() - 1];
        for (int x = nums.size() - 2; x >= 0; --x) {
            if(nums[x] <= dp[x + 1]) {
                dp[x] = dp[x + 1] + nums[x];
            }
            else {
                dp[x] = nums[x];
            }
        }

        return dp[0];
    }
};