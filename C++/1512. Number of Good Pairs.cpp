class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto& x : nums) {
            ++um[x];
        }
        int ans = 0;
        for (auto x : um) {
            if (x.second >= 2) {
                ans += (x.second - 1) * x.second / 2;
            }
        }
        return ans;
    }
};