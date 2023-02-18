class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int big = 1;
        int small = 1;
        int ans=INT_MIN;
        for(int x=0;x<nums.size();x++){
            if(nums[x]<0){
                big   = big ^ small;
                small = big ^ small;
                big   = big ^ small;
            }
            big = max(nums[x], nums[x]*big);
            small = min(nums[x], nums[x]*small);
            ans = max(ans, big);
        }
        return ans;
    }
};