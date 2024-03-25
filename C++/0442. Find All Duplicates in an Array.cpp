class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, bool> um;
        vector<int> ans;
        for(auto x : nums) {
            if (um[x] == false) {
                um[x] = true;
            }
            else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};