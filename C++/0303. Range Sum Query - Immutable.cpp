class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp.push_back(0);
        for(int x=0;x<nums.size();x++){
            dp.push_back(nums[x]+dp[x]);
        }
    }
    
    int sumRange(int left, int right) {
        return dp[right+1] - dp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */