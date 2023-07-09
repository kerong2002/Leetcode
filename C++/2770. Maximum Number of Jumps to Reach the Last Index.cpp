class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int size = nums.size();
        vector<double> dp(size + 1, -1);
        dp[0] = 0;
        dp[1] = 0;
        for (int y = 2; y <= size; ++y) {
            for (int x = y - 1; x >= 1; --x) {
                if (abs(nums[y - 1] - nums[x - 1]) <= target && dp[x] != -1) {
                    dp[y] = max(dp[y], dp[x] + 1);
                }
            }
//             for (auto x : dp) {
//                cout << x << " ";
//            }
//            cout << endl;
        }

        return dp[size];
    }
};