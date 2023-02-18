class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int x=1;x<nums.size();x++){
            nums[x] += nums[x-1];
        }
        return nums;
    }
};