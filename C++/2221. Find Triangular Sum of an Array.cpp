class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size = nums.size();
        for (int y = 1; y < size; ++y) {
            for (int x = size - 1; x >= y; --x) {
                nums[x] = (nums[x] + nums[x - 1]) % 10;
            }
        }

        return nums[size - 1];
    }
};