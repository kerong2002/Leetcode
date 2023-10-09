class Solution {
public:
    void binarySearch(vector<int>& ans, vector<int>& nums, const int target, int tail) {
        int mid = 0;
        int L = 0;
        int R = nums.size() - 1;
        int index = -1;
        while (L <= R) {
            mid = (L + R) / 2;
            if (nums[mid] > target) {
                R = mid - 1;
            }
            else if (nums[mid] < target) {
                L = mid + 1;
            }
            else {
                index = mid;
                if (tail) {
                    L = mid + 1;
                }
                else {
                    R = mid - 1;
                }
            }
            
        }
        ans[tail] = index;
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans({-1, -1});
        binarySearch(ans, nums, target, 0);
        binarySearch(ans, nums, target, 1);
        return ans;
    }
};