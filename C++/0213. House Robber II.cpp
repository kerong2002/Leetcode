class Solution {
public:
    int dp(vector<int>& arr,int pos, int size){
        int f1=0, f2=0, temp=0;
        for(int x=pos;x<size;x++){
            temp = f1;
            f1 = f2 + arr[x];
            f2 = max(f2,temp);
        }
        return max(f1, f2);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        else{
            return max(dp(nums, 0, nums.size()-1), dp(nums, 1, nums.size()));
        }
    }
};