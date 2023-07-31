class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int set_size = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
        for (int y = 0; y < nums.size(); ++y) {
            unordered_set<int> uq;
            for (int x = y; x < nums.size(); ++x) {
                uq.insert(nums[x]);
                if(uq.size() == set_size) {
                    ++ans;
                }
            }
                
        }
        return ans;
    }
};