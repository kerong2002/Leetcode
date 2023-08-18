class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int same[1001] = {0};
        for (auto x : nums1) {
            same[x] = 1;
        }
        for (auto x : nums2) {
            if (same[x]) {
                same[x] = 2;
            }
        }
        for (int x = 0; x < 1001; ++x) {
            if (same[x] == 2) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};