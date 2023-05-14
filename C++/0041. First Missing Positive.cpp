class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        unordered_set<int> us(nums.begin(), nums.end());
        int run = 1;
        
        while (run <= nums.size()) {
            if(us.count(run)) {
                ++run;
            }
            else {
                return run;
            }
        }

        return run;
    }
};