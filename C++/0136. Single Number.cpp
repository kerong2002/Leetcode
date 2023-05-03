class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int x=0;x<nums.size();x++){
            ans ^= nums[x];
        }
        return ans;
    }
};