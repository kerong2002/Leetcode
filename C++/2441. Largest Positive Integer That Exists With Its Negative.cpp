class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] >= 0 || nums[r] <= 0) {
                return -1;
            }
            if (-nums[l] == nums[r]) {
                return nums[r];
            }
            else if (-nums[l] > nums[r]) {
                ++l;
            }
            else{
                --r;
            }
        }
        return -1;
    }
};