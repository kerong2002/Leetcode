class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> save = nums;
        int r = nums.size()- k%nums.size();
        int l = 0;
        for(;r<nums.size();r++,l++){
            nums[l] = save[r];
        }
        r = 0;
        for(;l<nums.size();l++,r++){
            nums[l] = save[r];
        }
        return;
    }
};