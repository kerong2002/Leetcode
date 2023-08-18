class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int x = 0; x < nums.size(); ++x) {
            auto iter = um.find(target - nums[x]);
            if (iter != um.end()) {
                return {x,  iter->second};
            }
            um.insert({nums[x], x});
        }
        return {};
    }
};