class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() <= 0) {
            return 0;
        }
        int L = 0;
        int R = nums.size() - 1;
        while (R >  L && nums[R] == val) {
            nums.erase(nums.begin() + R);
            --R;
        }
        for (int x = L; x < nums.size(); ++x) {
            if(L >= R) {
                break;
            }
            else if(nums[x] == val) {
                swap(nums[x], nums[R]);
                while (R >  L && nums[R] == val) {
                    nums.erase(nums.begin() + R);
                    --R;
                }
            }
        }
        return nums[0] != val ? nums.size() : nums.size() - 1;
    }
};