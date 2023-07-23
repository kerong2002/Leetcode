class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        for (int x = 1; x <= size; ++x) {
            if(size % x == 0) {
                ans += static_cast<int>(pow(nums[x - 1], 2));
            }
        }
        return ans;
    }
};