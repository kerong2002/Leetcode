class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> um;
        for (auto y : nums1) {
            for (auto x : nums2) {
                ++um[x + y];
            }
        }
        int ans = 0;
        for (auto y : nums3) {
            for (auto x : nums4) {
                if (um.count(-(y + x))) {
                    ans += um[-(y + x)];
                }
            }
        }
        return ans;
    }
};