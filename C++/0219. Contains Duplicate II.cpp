class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int x = 0; x < nums.size(); ++x) {
            if (um.count(nums[x])) {
                if (abs(x - um[nums[x]]) <= k) {
                    return true;
                }
            }
            um[nums[x]] = x;
        }
        return false;
    }
};