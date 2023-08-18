class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        for (int y = 0; y < nums.size(); ++y) {
            for(int x = 0; x < y; ++x) {
                string a1 = to_string(nums[y]);
                char one = '0';
                char two = '0';
                for (auto c1 : a1) {
                    one = max(one, c1);
                }
                string a2 = to_string(nums[x]);
                for (auto c2 : a2) {
                   two = max(two, c2);
                }
                if(one == two) {
                    ans = max(ans, nums[y] + nums[x]);
                }
            }
        }
        return ans;
    }
};