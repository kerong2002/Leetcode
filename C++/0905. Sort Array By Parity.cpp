class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int L = 0;
        for (int x = 0; x < nums.size(); ++x) {
            if (nums[x] % 2) {
                continue;
            }
            else {
                swap(nums[L], nums[x]);
                ++L;
            }
        }
        return nums;
    }
};