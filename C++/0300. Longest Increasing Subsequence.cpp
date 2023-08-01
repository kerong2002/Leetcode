class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) {
            return 1;
        }
        int size = nums.size();
        vector<int> dp(size, 1);
        int ans = 0;
        for (int y = 1; y < nums.size(); ++y) {
            for (int x = 0; x < y; ++x) {
                if(nums[y] > nums[x]) {
                    dp[y] = max(dp[x] + 1, dp[y]);
                }
            }
            ans = max(ans, dp[y]);
        }
        return ans;
    }
};