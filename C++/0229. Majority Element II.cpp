class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cmp = nums.size() / 3 + 1;
        unordered_map<int, int> um;
        for (auto x : nums) {
            ++um[x];
        }
        vector<int> ans;
        for (auto x : um) {
            if (x.second >= cmp) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};