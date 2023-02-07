class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp(nums);
        dp[1] = max(nums[0], nums[1]);
        for(int x=2;x<nums.size();x++){
            dp[x] = max(dp[x-1], nums[x] + dp[x-2]);
        }
        return dp[nums.size()-1];
    }
};