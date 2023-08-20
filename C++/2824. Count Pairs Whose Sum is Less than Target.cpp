class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        for (int y = 0; y < nums.size(); ++y ) {
            for (int x = y + 1; x < nums.size(); ++x) {
                if (nums[x] + nums[y] < target) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};