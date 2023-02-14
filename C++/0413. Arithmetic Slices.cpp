class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int take = 0;
        for(int x=2;x<nums.size();x++){
            if(nums[x] == 2*nums[x-1]-nums[x-2]){
                ans += ++take;
            }
            else{
                take = 0;
            }
        }
        return ans;
    }
};