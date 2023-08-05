class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        vector<int> cnt(size, 1);
        int large = 1;
        int ans = 0;
        for (int y = 1; y < size; ++y) {
            for (int x = 0; x < y; ++x) {
                if(nums[y] > nums[x]) {
                    if(dp[x] + 1 > dp[y]) {
                        dp[y] = dp[x] + 1;
                        cnt[y] = cnt[x];
                    }
                    else if(dp[x] + 1 == dp[y]) {
                        cnt[y] += cnt[x];
                    }
                }
               
            }
            large = max(large, dp[y]);
        }
        for (int x = 0; x < size; ++x) {
            if(dp[x] == large) {
                ans += cnt[x];
            }
        }
        return ans;
    }
};