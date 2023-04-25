class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        int non_zero = 1;
        while(zero < non_zero && non_zero < nums.size()){
            if(nums[zero]==0 && nums[non_zero]!=0){
                swap(nums[non_zero++], nums[zero++]);
            }
            else if(nums[zero]==0 && nums[non_zero] == 0){
                non_zero += 1;
            }
            else{
                zero += 1;
                non_zero += 1;
            }
        }
        return;
    }
};