class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for(int x=0;x<nums.size();x++){
            if(max_jump<x){
                return false;
            }
            else{
                max_jump = max(x+nums[x], max_jump);
            }
        }
        return max_jump >= nums.size()-1;
    }
};