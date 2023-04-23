class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int x=0;x<nums.size();x++){
            nums[x] = nums[x]*nums[x];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};