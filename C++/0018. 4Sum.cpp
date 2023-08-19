class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int y = 0; y < nums.size(); ++y) {
            if (nums[y] > target && nums[y] >= 0) {
                break;
            }
            if (y > 0 && nums[y] == nums[y - 1]) {
                continue;
            }
            for (int x = y + 1; x < nums.size(); ++x) {
                if (nums[y] + nums[x] > target && nums[y] + nums[x] >= 0) {
                    break;
                }
                if (x > y + 1 && nums[x] == nums[x - 1]) {
                    continue;
                }
                int L = x + 1;
                int R = nums.size() - 1;
                while (L < R) {
                    if (static_cast<long long int> (nums[y] + nums[x]) + static_cast<long long int> (nums[L] + nums[R]) > target) {
                        --R;
                    }
                    else if (static_cast<long long int> (nums[y] + nums[x]) + static_cast<long long int> (nums[L] + nums[R]) < target) {
                        ++L;
                    }
                    else {
                        ans.push_back({nums[y], nums[x], nums[L], nums[R]});
                        while (R > L && nums[R] == nums[R - 1]) {
                            --R;
                        }
                        while (R > L && nums[L] == nums[L + 1]) {
                            ++L;
                        }
                        --R;
                        ++L;
                    }
                }
            }
        }
        return ans;
    }
};