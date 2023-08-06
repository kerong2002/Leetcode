class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size() <= 2) {
            return true;
        }
        for (int x = 1; x < nums.size(); ++x) {
            if(nums[x] + nums[x - 1] >= m) {
                return true;
            }
        }
        return false;
    }
};