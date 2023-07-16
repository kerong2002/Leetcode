class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        return (nums.size() + 1) * (nums.size()) / 2  - sum;
    }
};