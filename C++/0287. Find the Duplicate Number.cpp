class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto x : nums) {
            if (um.count(x)) {
                return x;
            }
            else {
                ++um[x];
            }
        }
        return -1;
    }
};