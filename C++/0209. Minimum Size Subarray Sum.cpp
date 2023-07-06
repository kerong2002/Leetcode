class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int R = 0;
        int sum = nums[R];
        int ans = INT_MAX;
        while (R < nums.size()) {
            if (sum < target) {
                ++R;
                if (R >= nums.size()) {
                    break;
                }
                sum+= nums[R];
            }
            else {
                ans = min(ans, R - L + 1);
                sum -= nums[L];
                if (L < R) {
                    ++L;
                }
            }

        }
        return ans == INT_MAX ? 0 : ans;
    }
};
