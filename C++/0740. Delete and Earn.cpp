class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(10001,0);
        int max=0;
        for(int x=0;x<nums.size();x++){
            dp[nums[x]]++;
            if(nums[x]>max){
                max=nums[x];
            }
        }
        for(int x=2;x<=max;x++){
            dp[x]=x*dp[x]+dp[x-2];
            if(dp[x-1]>dp[x]){
                dp[x]=dp[x-1];
            }
        }
        return dp[max];
    }
};