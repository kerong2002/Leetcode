class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0){
            return ans;
        }
        int run = nums[0];
        for (int x = 0; x < nums.size() - 1; ++x) {
            if ((long long int)nums[x + 1] - (long long int)nums[x] != (long long int)1) {
                if (run == nums[x]) {
                    ans.push_back(to_string(nums[x]));
                    run = nums[x + 1];
                }
                else {
                    ans.push_back(to_string(run) + "->" + to_string(nums[x]));
                    run = nums[x + 1];
                }
            }
        }
        if (nums[nums.size() - 1] == run) {
            ans.push_back(to_string(nums[nums.size() - 1]));
        }
        else {
            ans.push_back(to_string(run) + "->" + to_string(nums[nums.size() - 1]));
        }
        return ans;
    }
};