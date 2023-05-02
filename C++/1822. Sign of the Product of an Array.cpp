class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int x=0;x<nums.size();x++){
            if(nums[x] < 0){
                sign *= -1;
            }
            else if(nums[x] == 0){
                sign *= 0;
            }
        }
        return sign;
    }
};