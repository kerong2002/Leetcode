class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=0;
        int m=INT_MIN;
        for(int x=0;x<nums.size();x++){
            n += nums[x];
            if(n>m){
                m=n;
            }
            if(n<0){
                n=0;
            }
        }
        return m;
    }
};