class Solution {
public:
    void reverse(vector<int>&nums, int left, int right){
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums, 0  , nums.size()-1);
        reverse(nums, 0  , k%nums.size()-1);
        reverse(nums, k%nums.size()  , nums.size()-1);
        return;
    }
};